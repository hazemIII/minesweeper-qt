#include "MineSweeperApp.hpp"
#include <QDebug>
// Kocham Sysię!
MineSweeperApp::MineSweeperApp() 
{
  game = nullptr;
}

MineSweeperApp::~MineSweeperApp()
{
  if (game != nullptr)
  {
    delete game;
  }
}

void MineSweeperApp::newGame()
{
  qDebug() << "New Game";

  if (ngWindow.exec())
  {
    if (game != nullptr)
    {
      qDebug() << "Nie nullptr";
      delete game;
    }
    game = new Game(ngWindow.height, ngWindow.width, ngWindow.numOfMines, this);
    emit hideMainWindow();
  } else
  {
    if (game == nullptr)
    {
      QApplication::quit();
    }
  }
}

