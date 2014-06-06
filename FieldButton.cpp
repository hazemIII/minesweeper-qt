#include "FieldButton.hpp"

FieldButton::FieldButton(unsigned int x, unsigned int y, QWidget *parent)
{
  this->state = 0;
  this->x = x;
  this->y = y;
  this->setFixedSize(15,15);
  this->setCheckable(true);
}


void FieldButton::mousePressEvent(QMouseEvent *e)
{
  if (e->button() == Qt::LeftButton)
  {
    emit leftClick(x, y);
  } else if (e->button() == Qt::RightButton)
  {
    emit rightClick(x, y);
  }
}
