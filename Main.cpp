#include "PluginConfigDlg.h"
#include "Template.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  app.setQuitOnLastWindowClosed(true);

  PluginConfigDlg dlg;
  if (dlg.exec() == QDialog::Accepted)
  {
    PluginTemplate pluginTemplate("Templates/Plugin");
    pluginTemplate.run(dlg.getConfig());
    return 0;
  }

  return app.exec();
}
