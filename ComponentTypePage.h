#pragma once

#include "ui_WelcomeWidget.h"

#include <QWizardPage>

enum ComponentType
{
  PLUGIN,
  TASK,
  TEST,
  CLASS,
  NUM_VALUES
};

QString getComponentTypeName(ComponentType componentType);

class ComponentTypePage : public QWizardPage
{
public:
  explicit ComponentTypePage(QWidget* parent = nullptr);

private slots:

private:
  Ui::WelcomeWidget ui;
};
