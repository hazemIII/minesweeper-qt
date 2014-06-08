#include <QApplication>
#include "boardModel.hpp"
#include "MineSweeperApp.hpp"
#include "NewGameWindow.hpp"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  MineSweeperApp msAPP;
  return app.exec();
}
