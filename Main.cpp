#include "Wizard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Wizard wizard;
  wizard.resize(800, 400);
  wizard.show();

  return app.exec();
}
