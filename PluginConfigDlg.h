#ifndef PLUGINCONFIGDLG_H
#define PLUGINCONFIGDLG_H

#include "ui_PluginConfigDlg.h"

#include <QJsonObject>

class PluginConfigDlg : public QDialog
{
  Q_OBJECT

public:
  explicit PluginConfigDlg(QWidget* parent = nullptr);

  QJsonObject getConfig() const;

  void accept() override;

private slots:
  void onFolderNameChanged(const QString& pluginName);

private:
  Ui::PluginConfigDlg ui;
};

#endif // PLUGINCONFIGDLG_H
