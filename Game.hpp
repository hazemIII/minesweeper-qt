#ifndef GAME_HPP
#define GAME_HPP

#include <QObject>
#include <QTimer>
#include "BoardWindow.hpp"
#include "boardModel.hpp"

class Game : public QObject
{
  Q_OBJECT
  private:
    QTimer timer;
    int seconds;
    BoardWindow *gameWindow;
    BoardModel *model;
    QObject *parent;

  public:
    Game(int x, int y, int numOfMines, QObject *parent);
    ~Game();

  signals:
    void newGame();
    void leftClick(int, int);
    void rightClick(int, int);
    void flagField(int, int, bool);

  public slots:
    void endGame(bool won);

};

#endif
