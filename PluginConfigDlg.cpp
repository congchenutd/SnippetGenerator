#include "PluginConfigDlg.h"

PluginConfigDlg::PluginConfigDlg(QWidget *parent) :
  QDialog(parent)
{
  ui.setupUi(this);

  connect(ui.leFolderName, SIGNAL(textEdited(QString)), SLOT(onFolderNameChanged(QString)));
}

QJsonObject PluginConfigDlg::getConfig() const
{
  QJsonObject config;
  config.insert("$FOLDER_NAME$", ui.leFolderName->text());
  config.insert("$PLUGIN_NAME$", ui.lePluginName->text());
  config.insert("$WIDGET_NAME$", ui.leWidgetName->text());
  config.insert("$CONFIG_NAME$", ui.leConfigName->text());
  config.insert("$PLUGIN_DESCRIPTION$", ui.lePluginDescription->text());
  config.insert("$NAMESPACE$", ui.leNamespace->text());
  return config;
}

void PluginConfigDlg::accept()
{
  if (ui.leFolderName->text().isEmpty() ||
      ui.lePluginName->text().isEmpty() ||
      ui.lePluginDescription->text().isEmpty() ||
      ui.leWidgetName->text().isEmpty() ||
      ui.leConfigName->text().isEmpty())
  {
    return;
  }
  QDialog::accept();
}

void PluginConfigDlg::onFolderNameChanged(const QString& pluginName)
{
  ui.lePluginName->setText(pluginName + "Plugin");
  ui.leWidgetName->setText(pluginName + "Widget");
  ui.leConfigName->setText(pluginName + "PluginConfig");
}
