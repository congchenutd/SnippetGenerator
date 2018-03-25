#include "ConfigPage.h"

ConfigPage::ConfigPage(QWidget* parent) :
  QWizardPage(parent)
{
  ui.setupUi(this);

  setTitle("Configure the component");

  registerField("FolderName*",    ui.leFolderName);
  registerField("ComponentName*", ui.leComponentName);
  registerField("Description",    ui.lePluginDescription);
  registerField("ConfigName",     ui.leConfigName);
  registerField("WidgetName",     ui.leWidgetName);
  registerField("Namespaces",     ui.leNamespaces);

  // abc::edf
  ui.leNamespaces->setValidator(new QRegularExpressionValidator(QRegularExpression("(\\w+::)*\\w+?"), this));

  connect(ui.leFolderName, SIGNAL(textEdited(QString)), SLOT(onFolderNameChanged(QString)));
}

QJsonObject ConfigPage::getConfig() const
{
  QJsonObject config;
  config.insert("$FOLDER_NAME$",        ui.leFolderName->text());
  config.insert("$COMPONENT_NAME$",     ui.leComponentName->text());
  config.insert("$WIDGET_NAME$",        ui.leWidgetName->text());
  config.insert("$CONFIG_NAME$",        ui.leConfigName->text());
  config.insert("$PLUGIN_DESCRIPTION$", ui.lePluginDescription->text());
  config.insert("$NAMESPACES$",         ui.leNamespaces->text());
  return config;
}

void ConfigPage::initializePage()
{
  const bool isPlugin = field("IsPlugin").toBool();
  ui.labelDescription->setVisible(isPlugin);
  ui.lePluginDescription->setVisible(isPlugin);
  ui.labelWidgetName->setVisible(isPlugin);
  ui.leWidgetName->setVisible(isPlugin);
}

void ConfigPage::cleanupPage()
{
  ui.leFolderName->clear();
  ui.leComponentName->clear();
  ui.leWidgetName->clear();
  ui.leConfigName->clear();
  ui.leNamespaces->clear();
}

void ConfigPage::onFolderNameChanged(const QString& folderName)
{
  ui.leComponentName->setText(folderName);
  ui.leConfigName->setText(folderName + "Config");
  if (field("IsPlugin").toBool())
  {
    QString folderNameWithoutPlugin = folderName;
    folderNameWithoutPlugin.remove("Plugin");
    ui.leWidgetName->setText(folderNameWithoutPlugin + "Widget");
  }
}
