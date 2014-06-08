#ifndef MINESWEEPERAPP_HPP
#define MINESWEEPERAPP_HPP

#include <QObject>
#include "NewGameWindow.hpp"
#include "Game.hpp"

class MineSweeperApp : public QObject
{
  Q_OBJECT
  private:
    NewGameWindow ngWindow;
    Game *game;

  public:
    MineSweeperApp();
    ~MineSweeperApp();
  public slots:
    void newGame();
};
#endif
