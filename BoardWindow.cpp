#include "BoardWindow.hpp"
#include <QDebug>
#include <QSizePolicy>
#include <QString>

BoardWindow::BoardWindow(int height, int width, int numOfMines, QObject *parent)
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
  prepareButtons(height,width, numOfMines);
  show();
  this->resize(30,30);
  this->setFixedSize(this->size());
}

void BoardWindow::prepareButtons(unsigned int height, unsigned int width, unsigned int numOfMines)
{
  for (unsigned int i = 0; i<height; i++)
  {
    QList<FieldButton*> tmp;
    for (unsigned int j = 0; j<width; j++)
    {
      FieldButton *button = new FieldButton(i, j, this);
      button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
      tmp.append(button);
      boardLayout->addWidget(button, i, j);
      connect(button, SIGNAL(leftClick(int, int)), this, SIGNAL(leftClick(int, int)));
      connect(button, SIGNAL(rightClick(int, int)), this, SIGNAL(rightClick(int, int)));
      this->adjustSize();
    }
    buttons.append(tmp);
  }
  boardLayout->setSpacing(0);
  boardLayout->setMargin(0);
  //model->fill();
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


void BoardWindow::updateTime()
{
  timeWidget->display(timeWidget->intValue()+1);
}


void BoardWindow::updateTile(int x, int y, bool mine, int around, bool checked)
{  
  if (around != 0)
  {
    buttons[x][y]->setText(QString::number(around));
  }
  if (mine)
  {
    buttons[x][y]->setText("$");
  }
  buttons[x][y]->setChecked(checked);
}

void BoardWindow::endGame(bool won)
{
  //QPair<int, int> pair;
  //for(QPair<int, int> pair: model->bombTiles)
  //{

    //buttons[pair.first][pair.second]->setIcon(QIcon("/tmp/bomb.gif"));
    //buttons[pair.first ][pair.second]->setIconSize(buttons[pair.first][pair.second]->size());
  //}
  for (int i = 0; i<buttons.length(); i++)
  {
    for (int j = 0; j< buttons[0].length(); j++)
    {
      buttons[i][j]->setEnabled(false);
    }
  }
 QMessageBox msgBox;
 if (won)
 {
   msgBox.setText("Wygrana");
 } else
 {
   msgBox.setText("Przegana");
 }
 msgBox.exec();

}

void BoardWindow::wonGame()
{
  for (int i = 0; i<buttons.length(); i++)
  {
    for (int j = 0; j< buttons[0].length(); j++)
    {
      buttons[i][j]->setEnabled(false);
    }
  }
  QMessageBox msgBox;
  msgBox.setText("Wygrana!");
  msgBox.exec();
}

void BoardWindow::UTILE(int x, int y, int mines)
{
  buttons[x][y]->setText(mines>0?QString::number(mines):" ");
  buttons[x][y]->setChecked(true);
}

void BoardWindow::sendFlagField(int x, int y, bool flagged)
{
  buttons[x][y]->flagField(flagged);
}
