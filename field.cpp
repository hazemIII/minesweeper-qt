#include "field.hpp"
#include <QDebug>

Field::Field() : isMine(false), status(POINT_CLEAR)
{
  numOfMinesAround = countNumOfMinesAround();

}

void Field::setStatus(FieldStatus status)
{
  this->status = status;
}

unsigned char Field::countNumOfMinesAround()
{
  return 5;
}

void Field::setMine(bool isMine)
{
  this->isMine = isMine;
}
