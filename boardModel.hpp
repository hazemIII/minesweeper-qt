#ifndef BOARD_MODEL_HPP
#define BOARD_MODEL_HPP
#include <QList>
#include <QPair>
#include <QObject>
#include "field.hpp"
#include <cstdlib>
#include <time.h>

class BoardModel : public QObject
{
  Q_OBJECT
  private:
    QList<QList<Field*> > fields;


  public:
    BoardModel(unsigned int height, unsigned int width, int numOfMines);
    ~BoardModel();
    void fill();
    void revealField(int x, int y);
    unsigned int width;
    unsigned int height;
    int numOfMines;
    int numOfExposedFields;
    void calculateMine(int x, int y);

  signals:
    void setMinesAround(int x, int y, int mines);
    void utile(int x, int y, bool mine, int around, bool checked);
  public slots:
    void fieldClicked(int x, int y);
};
#endif
