#ifndef BOARD_MODEL_HPP
#define BOARD_MODEL_HPP
#include <QList>
#include <QPair>
#include <QObject>
#include <QVector>
#include "field.hpp"
#include <cstdlib>
#include <time.h>

class BoardModel : public QObject
{
  Q_OBJECT
  private:
    QList<QList<Field*> > fields;
    QObject *parent;


  public:
    BoardModel(unsigned int height, unsigned int width, int numOfMines, QObject *parent);
    ~BoardModel();
    void fill();
    unsigned int width;
    unsigned int height;
    int numOfMines;
    int numOfExposedFields;
    void calculateAround();
    QVector<QPair<int, int> > bombTiles;

  signals:
    void setMinesAround(int x, int y, int mines);
    void utile(int x, int y, bool mine, int around, bool checked);
    void wonGame();
  public slots:
    void revealField(int x, int y);
    void flagField(int x, int y);
    void fieldClicked(int x, int y);
    void addToDiscoveredFields();
};
#endif