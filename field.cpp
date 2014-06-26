#include "field.hpp"

Field::Field(int x, int y) : x(x), y(y), numOfMinesAround(0), flagged(false), discovered(false)
{
}

void Field::showBomb()
{

}

void Field::revealField()
{
}

void Field::flagField()
{
  if (!discovered)
  {
    flagged = !flagged;
    emit flagField(x, y, flagged);
  }
}

BombField::BombField(int x, int y): Field(x,y)
{

}

void BombField::revealField()
{
  emit endGame(false);
}

void BombField::showBomb()
{
  emit bombField(x, y);
}

void BombField::showField()
{
  this->showBomb();
}


EmptyField::EmptyField(int x, int y): Field(x,y)
{

}

void EmptyField::revealField()
{
  if (!discovered && !flagged)
  {
  this->discovered = true;
  emit updateTile(x, y, numOfMinesAround, discovered);
  emit revealField(x, y);
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

void EmptyField::showField()
{
  emit updateTile(x, y, numOfMinesAround, true);
}
