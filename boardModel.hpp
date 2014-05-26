#include <QList>
#include <QPair>
#include "field.hpp"

class BoardModel
{
  private:
    QList<QList<Field*> > fields;


  public:
    BoardModel(unsigned int height, unsigned int width, int numOfMines);
    void fill();
    void revealField(int x, int y);
    unsigned int width;
    unsigned int height;
    int numOfMines;
    int numOfExposedFields;
};
