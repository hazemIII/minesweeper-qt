#include "Game.hpp"
#include <QDebug>

Game::Game(int x, int y, int numOfMines, int playerId, QObject *parent) : seconds(0), playerId(playerId)
{
  timer.setInterval(1000);
  this->gameWindow = new BoardWindow(this);
  this->model = new BoardModel(x, y, numOfMines, this);
  gameWindow->setModel(model);
  model->setView(gameWindow);
  connect(gameWindow,SIGNAL(newGame()), parent, SLOT(newGame()));
  connect(&timer, SIGNAL(timeout()), gameWindow, SLOT(updateTime()));
  connect(&timer, &QTimer::timeout, [=]() { this->seconds++; });
  //connect(gameWindow, SIGNAL(leftClick(int, int)), model, SLOT(revealField(int, int)));
  //connect(model, SIGNAL(UTILE(int, int ,int)), gameWindow, SLOT(UTILE(int, int, int)));
  //connect(model, SIGNAL(endGame(bool)), this, SLOT(endGame(bool)));
  //connect(model, SIGNAL(showBomb(int, int)), gameWindow, SLOT(showBomb(int, int)));
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

