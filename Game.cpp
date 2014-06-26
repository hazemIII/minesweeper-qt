#include "Game.hpp"

Game::Game(int x, int y, int numOfMines, int playerId, QObject *parent) : seconds(0), playerId(playerId)
{
  timer.setInterval(1000);
  this->gameWindow = new BoardWindow(this);
  this->model = new BoardModel(x, y, numOfMines, this);
  gameWindow->setModel(model);
  model->setView(gameWindow);
  connect(gameWindow,SIGNAL(showMainMenu()), parent, SIGNAL(showMainMenu()));
  connect(gameWindow,SIGNAL(showMainMenu()), parent, SLOT(deleteGame()));
  connect(&timer, SIGNAL(timeout()), gameWindow, SLOT(updateTime()));
  connect(&timer, &QTimer::timeout, [=]() { this->seconds++; });
  timer.start();
}

Game::~Game()
{
  delete gameWindow;
  delete model;
}

void Game::endGame(bool won)
{
  timer.stop();
  DataBase *db = DataBase::getInstance();
  db->addGame(playerId, won, seconds, model->height, model->width, model->numOfMines, model->serializeBombs());
  model->showAllBombs();
}

