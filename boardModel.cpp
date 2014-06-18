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
  this->numOfExposedFields = 0;
  fields.reserve(height);
  this->fill();
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
  for (unsigned int i = 0; i < height; i++)
  {
    QList<Field*> tmp;
    for (unsigned int j = 0; j < width; j++)
    {
      Field *f = NULL;
      if ( bombTiles.contains(QPair<int, int>(i, j)))
      {
        f = new BombField(i, j);
        connect(f, SIGNAL(endGame(bool)), this, SIGNAL(endGame(bool)));
      }
      else 
      {
        f = new EmptyField(i, j);
        connect(f, SIGNAL(UTILE(int, int, int)), this, SIGNAL(UTILE(int, int, int)));
      }
      connect(f, SIGNAL(revealField(int, int)), this, SLOT(revealField(int, int)));
      connect(f, SIGNAL(flagField(int, int, bool)), this, SIGNAL(sendFlagField(int, int, bool)));
      connect(f, SIGNAL(addToDiscoveredFields()), this, SLOT(addToDiscoveredFields()));
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
    fields[x][y]->revealField();
  }
}
void BoardModel::fieldClicked(int x, int y)
{
    fields[x][y]->revealField();
}


void BoardModel::flagField(int x, int y)
{
  fields[x][y]->flagField();
}


void BoardModel::calculateAround()
{
  for(QPair<int, int> pair: bombTiles)
  {
        for (int i = pair.first-1; i<=pair.first+1; i++)
        {
          for (int j = pair.second-1; j<=pair.second+1; j++)
          {
            if (i >-1 && i < height && j > -1 && j < width)
            {
              (fields[i][j]->numOfMinesAround)++;
            }
          }
        }
  }

  for (int i = 0; i< height; i++)
  {
    for (int j = 0; j<width; j++)
    {
      if (bombTiles.contains(QPair<int, int>(i,j)))
      {
        std::cout <<"\033[35;1mB\033[0m" << " ";
      } else
      std::cout << fields[i][j]->numOfMinesAround << " ";
    }
    std::cout << "\n";
  }
}

void BoardModel::addToDiscoveredFields()
{
  numOfExposedFields++;
  if ((height*width)-numOfExposedFields == numOfMines)
  {
    emit endGame(true);
    showAllBombs();
  }
}

void BoardModel::showAllBombs()
{
  for(QPair<int, int> pair: bombTiles)
  {
    //emit sendFlagField(pair.first, pair.second, true);
    emit showBomb(pair.first, pair.second);
  }
}
