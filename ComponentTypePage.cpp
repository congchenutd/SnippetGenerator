#include "ComponentTypePage.h"

QString getComponentTypeName(ComponentType componentType)
{
  const std::vector<QString> string_values{"Plugin", "Task", "Test", "Class", "NUM_VALUES"};
  return string_values[static_cast<int>(componentType)];
}

ComponentTypePage::ComponentTypePage(QWidget *parent) :
  QWizardPage(parent)
{
  ui.setupUi(this);

  setTitle("Select component type");
  registerField("ComponentType", ui.comboComponentType);
}
