#include "BoardWindow.hpp"
#include <QDebug>
#include <QSizePolicy>
#include <QString>

BoardWindow::BoardWindow(QWidget *parent)
{
  newGameAction = this->menuBar()->addAction("Nowa gra");
  connect(newGameAction, SIGNAL(triggered()), this, SLOT(newGame()));

  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));


  centralWidget = new QWidget();
  this->setCentralWidget(centralWidget);
  this->timeWidget = new QLCDNumber(this);

  mainLayout = new QVBoxLayout();
  
  boardLayout = new QGridLayout();
  boardLayout->setHorizontalSpacing(0);
  boardLayout->setVerticalSpacing(0);
  
  upperLayout = new QHBoxLayout();
  upperLayout->addStretch(1);
  upperLayout->addWidget(timeWidget);

  mainLayout->addLayout(upperLayout);
  mainLayout->addLayout(boardLayout);
  centralWidget->setLayout(mainLayout);
  if (dial.exec())
  {
    qDebug() << "numm" << dial.numOfMines;
    prepareButtons(dial.height,dial.width, dial.numOfMines);
    show();
    timer->start(1000);
    this->resize(30,30);
    this->setFixedSize(this->size());
  } else
  {
      QApplication::quit();
  }
}

void BoardWindow::prepareButtons(unsigned int height, unsigned int width, unsigned int numOfMines)
{
  model = new BoardModel(height, width, numOfMines);
  connect(model, SIGNAL(utile(int, int, bool, int)), this, SLOT(updateTile(int, int, bool ,int)));
  for (unsigned int i = 0; i<height; i++)
  {
    QList<FieldButton*> tmp;
    for (unsigned int j = 0; j<width; j++)
    {
      FieldButton *button = new FieldButton(i, j, this);
      button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
      tmp.append(button);
      boardLayout->addWidget(button, i, j);
        connect(button, SIGNAL(KLIK(int, int)), model, SLOT(fieldClicked(int, int)));
      this->adjustSize();
    }
    buttons.append(tmp);
  }
  boardLayout->setSpacing(0);
  boardLayout->setMargin(0);
  model->fill();
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
  delete model;
  model = NULL;
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
  timer->stop();
  if (dial.exec())
  {
    hide();
    deleteButtons();
    prepareButtons(dial.height,dial.width, dial.numOfMines);
    setMaximumSize(QWIDGETSIZE_MAX,QWIDGETSIZE_MAX); setMinimumSize(0,0);
    timeWidget->display(0);
    show();
    this->resize(30,30);
    this->setFixedSize(this->size());
  } 
  timer->start(1000);
}

void BoardWindow::updateTime()
{
  timeWidget->display(timeWidget->intValue()+1);
}


void BoardWindow::updateTile(int x, int y, bool mine, int around)
{  
  if (around != 0)
  {
    buttons[x][y]->setText(QString::number(around));
  }
  if (mine)
  {
    buttons[x][y]->setText("$");
  }
}
