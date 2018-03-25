#pragma once

#include "ui_ConfigWidget.h"

#include <QWizardPage>
#include <QJsonObject>

class ConfigPage : public QWizardPage
{
  Q_OBJECT

public:
  explicit ConfigPage(QWidget* parent = nullptr);

  QJsonObject getConfig() const;
  void initializePage() override;
  void cleanupPage() override;

private slots:
  void onFolderNameChanged(const QString& folderName);

private:
  Ui::ConfigWidget ui;
};
