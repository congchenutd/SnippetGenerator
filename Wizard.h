#pragma once

#include <QWizard>

class ConfigPage;

class Wizard : public QWizard
{
public:
  Wizard(QWidget* parent = nullptr);

  void accept() override;

private:
  ConfigPage* _pageConfig;
};
