#include <QApplication>
#include "boardModel.hpp"
#include "BoardWindow.hpp"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  BoardModel model(10,10,10);
  BoardWindow mWindow(NULL, 10,4);
  return app.exec();
}
