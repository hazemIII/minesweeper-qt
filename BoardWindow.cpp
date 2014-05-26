#include "BoardWindow.hpp"
#include <QDebug>
#include <QSizePolicy>

BoardWindow::BoardWindow(QWidget *parent, unsigned int height, unsigned int width)
{
  newGameAction = this->menuBar()->addAction("Nowa gra");
  connect(newGameAction, SIGNAL(triggered()), this, SLOT(newGame()));

  centralWidget = new QWidget();
  this->setCentralWidget(centralWidget);
  this->timeWidget = new QLCDNumber(this);

  mainLayout = new QVBoxLayout();
  
  boardLayout = new QGridLayout();
  boardLayout->setHorizontalSpacing(0);
  boardLayout->setVerticalSpacing(0);
  
  upperLayout = new QHBoxLayout();
  upperLayout->addWidget(&button);
  upperLayout->addStretch(1);
  upperLayout->addWidget(timeWidget);

  mainLayout->addLayout(upperLayout);
  mainLayout->addLayout(boardLayout);
  centralWidget->setLayout(mainLayout);
  prepareButtons(height, width);
  show();
  this->resize(30,30);
  this->setFixedSize(this->size());
}

void BoardWindow::prepareButtons(unsigned int height, unsigned int width)
{
  for (unsigned int i = 0; i<height; i++)
  {
    QList<FieldButton*> tmp;
    for (unsigned int j = 0; j<width; j++)
    {
      FieldButton *button = new FieldButton(this);
      button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
      tmp.append(button);
      boardLayout->addWidget(button, i, j);
      this->adjustSize();
    }
    buttons.append(tmp);
  }
  boardLayout->setSpacing(0);
  boardLayout->setMargin(0);
}

void BoardWindow::deleteButtons()
{
  for (unsigned int i = 0; i<buttons.size(); i++)
  {
    for (unsigned int j = 0; j<buttons[0].size(); j++)
    {
      delete buttons[i][j];
    }
  }
  buttons.clear();
}

BoardWindow::~BoardWindow()
{
  delete boardLayout;
  delete upperLayout;
  delete mainLayout;
  delete timeWidget;
}

void BoardWindow::newGame()
{
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Nowa gra", "Na pewno?", QMessageBox::Yes|QMessageBox::No);
  if (reply == QMessageBox::Yes) 
  {
    //TODO :STUB is it?
    QApplication::quit();
  } 
}
