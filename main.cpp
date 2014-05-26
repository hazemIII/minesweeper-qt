#include <QApplication>
#include "boardModel.hpp"
#include "BoardWindow.hpp"
#include "NewGameWindow.hpp"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  BoardWindow boardWindow;
  return app.exec();
}
