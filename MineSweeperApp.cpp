#include "MineSweeperApp.hpp"

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
  if (playersWindow.exec())
  {
  if (ngWindow.exec())
  {
    if (game != nullptr)
    {
      delete game;
    }
    game = new Game(ngWindow.height, ngWindow.width, ngWindow.numOfMines, playersWindow.playerId, this);
    connect(game, SIGNAL(showMainMenu), this, SIGNAL(showMainMenu));
    emit hideMainWindow();
  } else
  {
    return;
  }
  } else
  {
    return;
  }
}

void MineSweeperApp::showDataBase()
{
  playersWindow.exec();
}

void MineSweeperApp::deleteGame()
{
  if (game != nullptr)
  {
    delete game;
  }
}
