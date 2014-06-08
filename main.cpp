#include <QApplication>
#include "boardModel.hpp"
#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  MainWindow mWindow;
  return app.exec();
}
