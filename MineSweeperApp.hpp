#ifndef MINESWEEPERAPP_HPP
#define MINESWEEPERAPP_HPP

#include <QObject>
#include "NewGameWindow.hpp"
#include "Game.hpp"
#include "DataBase.hpp"
#include "PlayersWindow.hpp"

class MineSweeperApp : public QObject
{
  Q_OBJECT
  private:
    Game *game;
    NewGameWindow ngWindow;
    DataBase *db;
    PlayersWindow winn;

  public:
    MineSweeperApp();
    ~MineSweeperApp();
  public slots:
    void newGame();

signals:
    void hideMainWindow();
};
#endif
