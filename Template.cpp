#include "Template.h"

#include <QJsonObject>
#include <QDebug>
#include <QFile>
#include <QDirIterator>
#include <QDate>

/**
 * @brief             Fill up the namespaces in a template
 * @param fileContent Content of a template
 * @param ns          Namespace value
 */
void applyNamespace(QString& fileContent, const QStringList& namespaces)
{
  // brace enclosed in c++ code
  if (namespaces.isEmpty())
  {
    fileContent.remove("$NAMESPACE_START$", Qt::CaseSensitive);
    fileContent.remove("$NAMESPACE_END$", Qt::CaseSensitive);
    return;
  }

  QString namespaceStart;
  for (const QString& section: namespaces)
  {
    namespaceStart += "namespace " + section + "\n{\n";
  }
  namespaceStart = namespaceStart.left(namespaceStart.length() - 1);  // remove last \n

  QString namespaceEnd;
  for (int i = namespaces.length() - 1; i >= 0; --i)
  {
    namespaceEnd += "}  // namespace " + namespaces.at(i) + "\n";
  }
  namespaceEnd = namespaceEnd.left(namespaceEnd.length() - 1);  // remove last \n

  fileContent.replace("$NAMESPACE_START$", namespaceStart, Qt::CaseSensitive);
  fileContent.replace("$NAMESPACE_END$", namespaceEnd, Qt::CaseSensitive);

  const QString oneLineSeparatedByDoubleColon = namespaces.join("::");
  fileContent.replace("$NAMESPACE_ONE_LINE_SEPARATED_BY_DOUBLE_COLON$", oneLineSeparatedByDoubleColon);

  // one-line namespace in asl
  const QString oneLineSeparatedByDot = namespaces.join(".");
  fileContent.replace("$NAMESPACE_ONE_LINE_SEPARATED_BY_DOT$", oneLineSeparatedByDot);
}

void applyYear(QString& fileContent)
{
  fileContent.replace("$YEAR$", QDate::currentDate().toString("yyyy"));
}

/**
 * @brief                   Generate code based on a template and config for the template
 * @param templateFilePath  Path of a template file
 * @param outputFilePath    Path of the generated code file
 * @param config            A config containing template placeholder values
 */
void applyTemplate(const QString& templateFilePath, const QString& outputFilePath, const QJsonObject& config)
{
  QFile inputFile(templateFilePath);
  if (!inputFile.open(QFile::ReadOnly))
    return;

  QDir::current().mkpath(QFileInfo(outputFilePath).path());
  QFile outputFile(outputFilePath);
  if (!outputFile.open(QFile::WriteOnly))
    return;

  QString content = inputFile.readAll();
  for (const auto& key: config.keys())
  {
    content.replace(key, config.value(key).toString(), Qt::CaseSensitive);
  }

  applyNamespace(content, config.value("$NAMESPACES$").toString().split("::"));
  applyYear(content);

  QTextStream os(&outputFile);
  os << content;
}

/**
 * @brief               Generate output file name
 * @param templatePath  Path of a template, which should be removed in the output file path
 * @param inputFileName Path of a template file
 * @param config        A config containing template placeholder values
 * @return
 */
QString createOutputFileName(const QString& templatePath, const QString& inputFileName, const QJsonObject& config)
{
  const auto& folderName = config.value("$FOLDER_NAME$").toString();
  if (folderName.isEmpty())
    return QString();
  QDir::current().mkpath("Output/" + folderName);

  const QString inputFilePath = QFileInfo(inputFileName).filePath().remove(templatePath);
  QString outputFileName = "Output/" + folderName + inputFilePath;
  for (const auto& key: config.keys())
  {
    if (outputFileName.contains(key, Qt::CaseSensitive))
    {
      outputFileName.replace(key, config.value(key).toString(), Qt::CaseSensitive);
      break;
    }
  }
  return outputFileName;
}

///////////////////////////////////////////////////////////////////////////////////
Template::Template(const QString& path)
  : _path(path)
{

}

void Template::run(const QJsonObject& config) const
{
  QDirIterator it(_path, QDir::Files, QDirIterator::Subdirectories);
  while (it.hasNext())
  {
    const QString templateFileName = it.next();
    const QString outputFileName = createOutputFileName(_path, templateFileName, config);
    applyTemplate(templateFileName, outputFileName, config);
  }
}
