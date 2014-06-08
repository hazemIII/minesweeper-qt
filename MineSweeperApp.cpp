#include "MineSweeperApp.hpp"
// Kocham Sysię!
MineSweeperApp::MineSweeperApp() 
{
  game = nullptr;
  newGame();

}

MineSweeperApp::~MineSweeperApp()
{

}

void MineSweeperApp::newGame()
{
  if (ngWindow.exec())
  {
    game = new Game(ngWindow.height, ngWindow.width, ngWindow.numOfMines, this);
  }
}
