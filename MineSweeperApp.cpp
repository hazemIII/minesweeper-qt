#include "MineSweeperApp.hpp"
#include <QDebug>
// Kocham Sysię!
MineSweeperApp::MineSweeperApp() 
{
  game = nullptr;
}

MineSweeperApp::~MineSweeperApp()
{

}

void MineSweeperApp::newGame()
{
  if (ngWindow.exec())
  {
    game = new Game(ngWindow.height, ngWindow.width, ngWindow.numOfMines, this);
    emit hideMainWindow();
  } else
  {
  qDebug() << "New Game";
    QApplication::quit();
  }
}
