#include "FieldButton.hpp"

FieldButton::FieldButton(QWidget *parent)
{
  this->setFixedSize(15,15);
  this->setCheckable(true);
}


void FieldButton::mousePressEvent(QMouseEvent *e)
{
  //this->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255, 255, 255)");
  try{
    if(e->button()==Qt::LeftButton){
    this->setChecked(true);  
    this->setText("#");
    if(state==0)
    state=1;
    else if(state==2){
    state=3;
    }
    }else if(e->button()==Qt::RightButton){
  this->setChecked(false);  
  this->setText("");
    if(state==0){
    state=2;
    }else if(state==1){
    state=3;
    }
    }
  }catch(std::exception e){
  //do nothing
  }
}
