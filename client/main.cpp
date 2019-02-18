#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWidget widget;

  widget.show();
  app.exec();
}
