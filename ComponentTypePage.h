#pragma once

#include "ui_WelcomeWidget.h"

#include <QWizardPage>

class ComponentTypePage : public QWizardPage
{
public:
  explicit ComponentTypePage(QWidget* parent = nullptr);

  bool isComplete() const override;

private:
  Ui::WelcomeWidget ui;
};
