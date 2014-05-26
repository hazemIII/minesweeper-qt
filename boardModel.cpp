#include "boardModel.hpp"

BoardModel::BoardModel(unsigned int height, unsigned int width, int numOfMines) 
{
  this->height = height;
  this->width = width;
  this->numOfMines = numOfMines;
  numOfExposedFields = 0;
  fields.reserve(height);
  for (unsigned int i = 0; i<height; i++)
  {
    QList<Field*> tmp;

    for (unsigned int j = 0; j<width; j++)
    {
      tmp.append(new Field());
    }
    fields.append(tmp);
  }
  fill();
}

void BoardModel::fill()
{
  for (unsigned int i = 0; i<height; i++)
  {
    for (unsigned int j = 0; j<width; j++)
    {
      fields[i][j]->setMine(true);
    }
  }
}

void BoardModel::revealField(int x, int y)
{

}
