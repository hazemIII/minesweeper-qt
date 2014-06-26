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
    PlayersWindow playersWindow;

  public:
    MineSweeperApp();
    ~MineSweeperApp();
  public slots:
    void newGame();
    void showDataBase();

signals:
    void hideMainWindow();
};
#endif
