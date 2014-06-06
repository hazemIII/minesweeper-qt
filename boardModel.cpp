#include "boardModel.hpp"
#include <QDebug>
#include <QPair>
#include <iostream>
BoardModel::BoardModel(unsigned int height, unsigned int width, int numOfMines, QObject *parent) 
{
  srand(time(NULL));
  this->parent = parent;
  this->height = height;
  this->width = width;
  this->numOfMines = numOfMines;
  fields.reserve(height);
}

BoardModel::~BoardModel()
{

}

void BoardModel::fill()
{
  for (int i = 0; i < numOfMines; i++)
  {
    bombTiles.append(QPair<int, int>(rand() % height, rand() % width));
  }
  qDebug() << "serialize" << bombTiles;
  for (int i = 0; i < height; i++)
  {
    QList<Field*> tmp;
    for (int j = 0; j < width; j++)
    {
      Field *f = NULL;
      if ( bombTiles.contains(QPair<int, int>(i, j)))
      {
        f = new BombField(i, j);
        connect(f, SIGNAL(endGame()), parent, SLOT(endGame()));
      }
      else 
      {
        f = new EmptyField(i, j);
        connect(f, SIGNAL(UTILE(int, int, int)), parent, SLOT(UTILE(int, int, int)));
      }
      connect(f, SIGNAL(revealField(int, int)), this, SLOT(revealField(int, int)));
      tmp.append(f);
    }
    fields.append(tmp);
  }
  calculateAround();
}

void BoardModel::revealField(int x, int y)
{ 
  if (x >-1 && x < height && y > -1 && y < width)
  {
    qDebug() << fields[x][y]->metaObject()->className();
    fields[x][y]->revealField();
    //emit utile(x,y, false, fields[x][y]->numOfMinesAround, true);
  }
}
void BoardModel::fieldClicked(int x, int y)
{
    fields[x][y]->revealField();
}


void BoardModel::flagField(int x, int y)
{

}


void BoardModel::calculateAround()
{
  for (int x= 0; x < height; x++)
  {
    for (int y = 0; y < width; y++)
    {
      if (bombTiles.contains(QPair<int, int>(x,y)))
      {
        for (int i = x-1; i<=x+1; i++)
        {
          for (int j = y-1; j<=y+1; j++)
          {
            if (i >-1 && i < height && j > -1 && j < width)
            {
              (fields[i][j]->numOfMinesAround)++;
            }
          }
        }
      }
    }
  }

  for (int i = 0; i< height; i++)
  {
    for (int j = 0; j<width; j++)
    {
      std::cout << fields[i][j]->numOfMinesAround << " ";
    }
    std::cout << "\n";
  }

}
