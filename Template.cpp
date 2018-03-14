#include "Template.h"

#include <QJsonObject>
#include <QDebug>
#include <QFile>
#include <QDirIterator>

void applyNamespace(QString& fileContent, const QString& ns)
{
  if (ns.isEmpty())
  {
    fileContent.remove("$NAMESPACE_START$", Qt::CaseSensitive);
    fileContent.remove("$NAMESPACE_END$", Qt::CaseSensitive);
    return;
  }

  const QStringList sections = ns.split("::");
  QString namespaceStart;
  for (const QString& section: sections)
  {
    namespaceStart += "namespace " + section + "\n{\n";
  }
  namespaceStart = namespaceStart.left(namespaceStart.length() - 1);  // remove last \n

  QString namespaceEnd;
  for (int i = sections.length() - 1; i >= 0; --i)
  {
    namespaceEnd += "}  // namespace " + sections.at(i) + "\n";
  }
  namespaceEnd = namespaceEnd.left(namespaceEnd.length() - 1);  // remove last \n

  fileContent.replace("$NAMESPACE_START$", namespaceStart, Qt::CaseSensitive);
  fileContent.replace("$NAMESPACE_END$", namespaceEnd, Qt::CaseSensitive);
}

void applyTemplate(const QString& inputFilePath, const QString& outputFilePath, const QJsonObject& config)
{
  QFile inputFile(inputFilePath);
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

  applyNamespace(content, config.value("$NAMESPACE$").toString());

  QTextStream os(&outputFile);
  os << content;
}

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

Template::Template(const QString& path)
  : _path(path)
{

}

QString Template::getPath() const
{
  return _path;
}

void Template::setPath(const QString& path)
{
  _path = path;
}

PluginTemplate::PluginTemplate(const QString& path)
  : Template(path)
{

}

void PluginTemplate::run(const QJsonObject& config) const
{
  QDirIterator it(_path, QDir::Files, QDirIterator::Subdirectories);
  while (it.hasNext())
  {
    const QString inputFileName = it.next();
    const QString outputFileName = createOutputFileName(_path, inputFileName, config);
    applyTemplate(inputFileName, outputFileName, config);
  }

//  for (const auto& key: config.keys())
//  {
//    QString value = config.value(key).toString();
//    qDebug() << key << ":" << value;
//  }
}
