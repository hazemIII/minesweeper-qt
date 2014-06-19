#include "FieldButton.hpp"

#include <QDebug>
FieldButton::FieldButton(unsigned int x, unsigned int y, QWidget *parent)
{
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

void FieldButton::flagField(bool flagged)
{
  if (flagged)
  {
  this->setIcon(QIcon("flag.gif"));
  this->setIconSize(this->size());
  } else
  {
    this->setIcon(QIcon());
  }
}

void FieldButton::showBomb()
{
  this->setIcon(QIcon("bomb.gif"));
  this->setIconSize(this->size());
}

void FieldButton::updateTile(int around, bool discovered)
{
  if (discovered)
  {
    if (around != 0)
    {
      setText(QString::number(around));
    }
  } else
  {
    setText("");
  }
  setChecked(discovered);

}
