#include "ComponentTypePage.h"

ComponentTypePage::ComponentTypePage(QWidget *parent) :
  QWizardPage(parent)
{
  ui.setupUi(this);

  setTitle("Select component type");
  registerField("IsPlugin", ui.radioPlugin);
  registerField("IsTask", ui.radioTask);

  connect(ui.radioPlugin, SIGNAL(clicked(bool)), SIGNAL(completeChanged()));
  connect(ui.radioTask,   SIGNAL(clicked(bool)), SIGNAL(completeChanged()));
}

bool ComponentTypePage::isComplete() const
{
  return ui.radioPlugin->isChecked() || ui.radioTask->isChecked();
}
