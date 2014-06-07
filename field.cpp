#include "field.hpp"
#include <QDebug>

Field::Field(int x, int y) : x(x), y(y), numOfMinesAround(0), discovered(false), flagged(false)
{
}


void Field::revealField()
{
}

void Field::flagField()
{

  if (!discovered)
  {
    emit flagField(x, y, !flagged);
    flagged = !flagged;
  }
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
  if (!discovered && !flagged)
  {
  this->discovered = true;
  emit revealField(x, y);
  emit UTILE(x, y, numOfMinesAround);
  emit addToDiscoveredFields();
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

