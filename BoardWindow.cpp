#include "BoardWindow.hpp"
#include <QSizePolicy>
#include <QString>

BoardWindow::BoardWindow(bool game, QObject *parent)
{
  this->parent = parent;
  centralWidget = new QWidget();
  this->setCentralWidget(centralWidget);
  boardLayout = new QGridLayout();
  boardLayout->setHorizontalSpacing(0);
  boardLayout->setVerticalSpacing(0);
  if (game)
  {
    mainMenuAction = this->menuBar()->addAction("Menu główne");
    connect(mainMenuAction, SIGNAL(triggered()), this, SIGNAL(showMainMenu()));

    this->timeWidget = new QLCDNumber(this);

    mainLayout = new QVBoxLayout();

    upperLayout = new QHBoxLayout();
    upperLayout->addStretch(1);
    upperLayout->addWidget(timeWidget);

    mainLayout->addLayout(upperLayout);
    mainLayout->addLayout(boardLayout);
    centralWidget->setLayout(mainLayout);
  } else
  {
    this->upperLayout = nullptr;
    this->mainLayout = nullptr;
    this->timeWidget = nullptr;

    boardLayout = new QGridLayout();
    boardLayout->setHorizontalSpacing(0);
    boardLayout->setVerticalSpacing(0);

    centralWidget->setLayout(boardLayout);
  }
}


void BoardWindow::setModel(BoardModel *model)
{
  this->model = model;
  prepareButtons(model->height,model->width);
  show();
  this->resize(30,30);
  this->setFixedSize(this->size());
}

void BoardWindow::prepareButtons(int height, int width)
{
  for (int i = 0; i<height; i++)
  {
    QList<FieldButton*> tmp;
    for (int j = 0; j<width; j++)
    {

      FieldButton *button = new FieldButton(i, j);
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

