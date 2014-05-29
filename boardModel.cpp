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
            //emit utile(i,j, fields[i][j]->isMine, fields[i][j]->numOfMinesAround, false);
          }
          std::cout << std::endl;
        }
}

void BoardModel::revealField(int x, int y)
{ 
  if (x >-1 && x < height && y > -1 && y < width)
  {
    qDebug() << "REVEAL"  << x << "  " << y;
    if (fields[x][y]->isMine)
    {
      qDebug() << fields[x][y];
      return;
    }
    if (fields[x][y]->status==POINT_DISCOVERED) return;  // już odkryte wyjście

    if(!(fields[x][y]->isMine) && fields[x][y]->status!=POINT_DISCOVERED)
    fields[x][y]->setStatus(POINT_DISCOVERED);   // odkryj!
    emit utile(x,y, fields[x][y]->isMine, fields[x][y]->numOfMinesAround, true);

    if (fields[x][y]->numOfMinesAround!=0) return; // wartość > 0 wyjście

    //wywołanie funkcji dla każdego sąsiada
    revealField(x-1,y-1);
    revealField(x-1,y);
    revealField(x-1,y+1);
    revealField(x+1,y-1);
    revealField(x+1,y);
    revealField(x+1,y+1);
    revealField(x,y-1);
    revealField(x,y);
    revealField(x,y+1);
  }
}

void BoardModel::fieldClicked(int x, int y)
{
  revealField(x,y);

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
