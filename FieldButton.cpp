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
  emit KLIK(x, y);
  if(e->button()==Qt::LeftButton)
  {
    this->setChecked(true);  
    this->setText("#");
    if(state==FIELD_CLEAR)
    {
      state=FIELD_DISCOVERED;
      this->setStyleSheet("");
      this->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255, 255, 255)");
      this->setEnabled(false);
    } else if (state == FIELD_FLAGGED)
    {
      state=FIELD_DISCOVERED;
      this->setStyleSheet("");
      this->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255, 255, 255)");
      this->setEnabled(false);
    }
  } else if(e->button()==Qt::RightButton)
  {
    this->setChecked(false);  
    this->setText("");
    if(state==FIELD_CLEAR)
    {
      state=FIELD_FLAGGED;
      this->setStyleSheet("");
      this->setStyleSheet("background-color: rgb(0, 233, 0); color: rgb(255, 255, 255)");
    } else if (state == FIELD_FLAGGED)
    {
      state = FIELD_CLEAR;
      this->setStyleSheet("");
    }
  }
}
