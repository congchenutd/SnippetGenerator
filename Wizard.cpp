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
  const QString templatePath = field("IsPlugin").toBool() ? "Templates/Plugin"
                                                          : "Templates/Task";
  Template snippetTemplate(templatePath);
  snippetTemplate.run(_pageConfig->getConfig());
  QWizard::accept();
}
