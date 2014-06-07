#include "Game.hpp"

Game::Game(BoardWindow *gameWindow) : seconds(0)
{
  timer.setInterval(1000);
  this->gameWindow = gameWindow;
}

Game::~Game()
{

}
