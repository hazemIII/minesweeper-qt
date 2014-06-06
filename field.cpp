#include "field.hpp"
#include <QDebug>

Field::Field(int x, int y) : x(x), y(y), numOfMinesAround(0), discovered(false)
{
}


void Field::revealField()
{
}


BombField::BombField(int x, int y): Field(x,y)
{

}

void BombField::revealField()
{
  emit endGame();
}


EmptyField::EmptyField(int x, int y): Field(x,y)
{

}

void EmptyField::revealField()
{
  if (!discovered)
  {
  this->discovered = true;
  emit revealField(x, y);
  emit UTILE(x, y, numOfMinesAround);
  if (numOfMinesAround == 0)
  {
    for (int i=x-1; i<= x+1; i++)
    {
      for (int j = y-1; j<= y+1; j++)
      {
        emit revealField(i, j);
      }
    }
  }
}

}

