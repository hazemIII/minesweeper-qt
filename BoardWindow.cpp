#include "BoardWindow.hpp"
#include <QDebug>
#include <QSizePolicy>
#include <QString>

BoardWindow::BoardWindow(QObject *parent)
{
  this->parent = parent;
  newGameAction = this->menuBar()->addAction("Nowa gra");
  connect(newGameAction, SIGNAL(triggered()), this, SIGNAL(newGame()));

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
}
BoardWindow::BoardWindow(int height, int width, QString bombs, QObject *parent)
{
  this->parent = parent;
  this->upperLayout = nullptr;
  this->mainLayout = nullptr;
  this->timeWidget = nullptr;

  centralWidget = new QWidget();
  this->setCentralWidget(centralWidget);

  boardLayout = new QGridLayout();
  boardLayout->setHorizontalSpacing(0);
  boardLayout->setVerticalSpacing(0);

  centralWidget->setLayout(boardLayout);
  qDebug() << "init";
}


void BoardWindow::setModel(BoardModel *model)
{
  this->model = model;
  prepareButtons(model->height,model->width, model->numOfMines);
  show();
  this->resize(30,30);
  this->setFixedSize(this->size());
  qDebug() << "setModel";
}

void BoardWindow::prepareButtons(unsigned int height, unsigned int width, unsigned int numOfMines)
{
  qDebug() << "prepareButtons" << height << width;
  for (unsigned int i = 0; i<height; i++)
  {
    QList<FieldButton*> tmp;
    for (unsigned int j = 0; j<width; j++)
    {
      FieldButton *button = new FieldButton(i, j, this);
      button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
      tmp.append(button);
      boardLayout->addWidget(button, i, j);
      connect(button, SIGNAL(leftClick(int, int)), model, SLOT(leftClick(int, int)));
      connect(button, SIGNAL(rightClick(int, int)), model, SLOT(rightClick(int, int)));
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
  if (upperLayout != nullptr)
  {
    delete upperLayout;
    delete mainLayout;
    delete timeWidget;
  }
  for(QList<FieldButton*> tmp: buttons)
  {
    for (FieldButton *button: tmp)
    {
      delete button;
    }
  }
}


void BoardWindow::updateTime()
{
  timeWidget->display(timeWidget->intValue()+1);
}


void BoardWindow::updateTile(int x, int y, int around, bool discovered)
{  
  buttons[x][y]->updateTile(around, discovered);
}

void BoardWindow::UTILE(int x, int y, int mines)
{
  buttons[x][y]->setText(mines>0?QString::number(mines):" ");
  buttons[x][y]->setChecked(true);
}


void BoardWindow::bombField(int x, int y)
{
  buttons[x][y]->showBomb();
}

void BoardWindow::flagField(int x, int y, bool flagged)
{
  buttons[x][y]->flagField(flagged);
}

void BoardWindow::endGame(bool won)
{
  QMessageBox msgBox;
  if (won)
  {
    msgBox.setText("Wygrana");
  } else
  {
    for(QList<FieldButton*> tmp: buttons)
    {
      for (FieldButton *button: tmp)
      {
        button->setEnabled(false);
      }
    }
    msgBox.setText("Przegana");
  }
  msgBox.exec();
}

