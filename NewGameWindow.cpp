#include "NewGameWindow.hpp"
#include <QDebug>

NewGameWindow::NewGameWindow(QWidget *parent, Qt::WindowFlags f)
{

  ui.setupUi(this);
  connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(checkValues()));
  connect(ui.heightBox, SIGNAL(valueChanged(int)), this, SLOT(setMaxMinesCount()));
  connect(ui.widthBox, SIGNAL(valueChanged(int)), this, SLOT(setMaxMinesCount()));
  on_beginnerButton_toggled(true);
    
}

NewGameWindow::~NewGameWindow()
{

}

void NewGameWindow::checkValues()
{
  qDebug() << "checkValues";
  height = ui.heightBox->value();
  width = ui.widthBox->value();
}

void NewGameWindow::setMaxMinesCount()
{
  ui.numOfMinesBox->setMaximum(ui.heightBox->value() * ui.widthBox->value());
}

void NewGameWindow::on_idiotButton_toggled(bool state)
{
  if (state == true)
  {
    ui.heightBox->setValue(99);
    ui.widthBox->setValue(99);
    ui.numOfMinesBox->setValue(1);
  }
}

void NewGameWindow::on_beginnerButton_toggled(bool state)
{
  if (state == true)
  {
    ui.heightBox->setValue(15);
    ui.widthBox->setValue(15);
    ui.numOfMinesBox->setValue(10);
  }
}

void NewGameWindow::on_advancedButton_toggled(bool state)
{
  if (state == true)
  {
    ui.heightBox->setValue(30);
    ui.widthBox->setValue(30);
    ui.numOfMinesBox->setValue(60);
  }
}
