#include "boardModel.hpp"
#include <QDebug>
#include <iostream>
BoardModel::BoardModel(unsigned int height, unsigned int width, int numOfMines) 
{
  srand(time(NULL));
  this->height = height;
  this->width = width;
  this->numOfMines = numOfMines;
  numOfExposedFields = 0;
  fields.reserve(height);
  for (unsigned int i = 0; i<height; i++)
  {
    QList<Field*> tmp;

    for (unsigned int j = 0; j<width; j++)
    {
      tmp.append(new Field());
    }
    fields.append(tmp);
  }
}

BoardModel::~BoardModel()
{

}

void BoardModel::fill()
{
  qDebug() << "NIM" <<numOfMines;
  for (int i = 0; i < numOfMines; i++)
  {
    fields[rand()%height][rand()%width]->setMine(true);
  }
  for (unsigned int i = 0; i<height; i++)
  {
    for (unsigned int j = 0; j<width; j++)
    {
      calculateMine(i,j);
    }
  }
        for (unsigned int i = 0; i<height; i++)
        {
          for (unsigned int j = 0; j<width; j++)
          {
            std::cout << (unsigned int) fields[i][j]->numOfMinesAround << (unsigned int) fields[i][j]->isMine<<" ";
            emit utile(i,j, fields[i][j]->isMine, fields[i][j]->numOfMinesAround);
          }
          std::cout << std::endl;
        }
}

void BoardModel::revealField(int x, int y)
{

}

void BoardModel::fieldClicked(int x, int y)
{
  qDebug() << x << "  " << y;

}

void BoardModel::calculateMine(int x, int y)
{
  if (fields[x][y]->isMine)
  {
    for (int i = x-1; i<=x+1; i++)
    {
      for (int j = y-1; j<=y+1; j++)
      {
        qDebug() << i << "  "<<j;
          if (i >-1 && i < height && j > -1 && j < width)
          {
          if(!fields[i][j]->isMine)
          {
            (fields[i][j]->numOfMinesAround)++;
          }
          }
      }
    }
  }
}
