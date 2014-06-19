#include "MineSweeperApp.hpp"
#include <QDebug>
// Kocham Sysię!
MineSweeperApp::MineSweeperApp() 
{
  game = nullptr;
  db = &(DataBase::getInstance());
  winn.show();
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
  if (ngWindow.exec())
  {
    if (game != nullptr)
    {
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

