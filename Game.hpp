#ifndef GAME_HPP
#define GAME_HPP

#include <QObject>
#include <QTimer>
#include "BoardWindow.hpp"

class Game : public QObject
{
  Q_OBJECT
  private:
    QTimer timer;
    int seconds;
    BoardWindow *gameWindow;

  public:
    Game(BoardWindow *gameWindow);
    ~Game();

};

#endif
