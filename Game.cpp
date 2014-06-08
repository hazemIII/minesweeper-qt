#include "Game.hpp"

Game::Game(int x, int y, int numOfMines, QObject *parent) : seconds(0)
{
  timer.setInterval(1000);
  this->gameWindow = new BoardWindow(x, y, numOfMines, this);
  this->model = new BoardModel(x, y, numOfMines, this);
  connect(gameWindow,SIGNAL(newGame()), parent, SLOT(newGame()));
}

Game::~Game()
{

}
