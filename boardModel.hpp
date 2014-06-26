#ifndef BOARD_MODEL_HPP
#define BOARD_MODEL_HPP
#include <QList>
#include <QPair>
#include <QObject>
#include <QVector>
#include <QStringList>
#include "field.hpp"
#include <cstdlib>
#include <time.h>
#include <QPair>

#ifdef QT_DEBUG
#include <iostream>
#endif

class BoardModel : public QObject
{
  Q_OBJECT
  private:
    QList<QList<Field*> > fields;
    QObject *parent;
    QObject *view;
    QVector<QPair<int, int> > bombTiles;


  public:
    BoardModel(unsigned int height, unsigned int width, int numOfMines, QObject *parent = 0);
    BoardModel(unsigned int height, unsigned int width, QString bombs, QObject *parent = 0);
    ~BoardModel();
    void setBombs(QString bombs);
    void setBombs();
    void fill();
    int width;
    int height;
    int numOfMines;
    int numOfExposedFields;
    void calculateAround(QVector<QPair<int, int> > bombTiles);
    void showAllBombs();
    void setView(QObject *view);
    QString serializeBombs();
    void revealAllFields();

  signals:
    void winGameGame();
    void UTILE(int, int, int);
    void sendFlagField(int, int, bool);
    void endGame(bool);
    void showBomb(int, int);

    void updateTile(int, bool);

  public slots:
    void revealField(int x, int y);
    void addToDiscoveredFields();

    void leftClick(int x, int y);
    void rightClick(int x, int y);
};
#endif
