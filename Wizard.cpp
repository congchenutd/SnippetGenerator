#include "Wizard.h"
#include "ConfigPage.h"
#include "ComponentTypePage.h"
#include "Template.h"

Wizard::Wizard(QWidget* parent)
  : QWizard(parent)
{
  addPage(new ComponentTypePage);
  _pageConfig = new ConfigPage;
  addPage(_pageConfig);

  setWindowTitle("Snippet Generator");
}

void Wizard::accept()
{
  const ComponentType componentType = static_cast<ComponentType>(field("ComponentType").toInt());
  const QString componentTypeName = getComponentTypeName(componentType);
  const QString templatePath = "Templates/" + componentTypeName;
  Template snippetTemplate(templatePath);
  snippetTemplate.run(_pageConfig->getConfig());
  QWizard::accept();
}
