#include "boardModel.hpp"

BoardModel::BoardModel(unsigned int height, unsigned int width, int numOfMines, QObject *parent) 
{
  srand(time(NULL));
  this->parent = parent;
  this->height = height;
  this->width = width;
  this->numOfMines = numOfMines;
  this->numOfExposedFields = 0;
  fields.reserve(height);
  setBombs();
}
BoardModel::BoardModel(unsigned int height, unsigned int width, QString bombs, QObject *parent)
{
  this->parent = parent;
  this->height = height;
  this->width = width;
  this->numOfMines = 0;
  this->numOfExposedFields = 0;
  setBombs(bombs);

}

BoardModel::~BoardModel()
{

}

void BoardModel::setView(QObject *view)
{
  this->view = view;
  this->fill();
  if ( parent != 0)
  {
    connect(this, SIGNAL(endGame(bool)), view, SLOT(endGame(bool)));
    connect(this, SIGNAL(endGame(bool)), parent, SLOT(endGame(bool)));
  }
}

void BoardModel::setBombs(QString bombs)
{
  QStringList tmp  = bombs.split(" ", QString::SkipEmptyParts);
  for(QString coordinateString : tmp)
  {
    QStringList coordinates = coordinateString.split(":");
    bombTiles.append(QPair<int, int>(coordinates[0].toInt(), coordinates[1].toInt()));
  }
}

void BoardModel::setBombs()
{
  for (int i = 0; i < numOfMines; i++)
  {
    bombTiles.append(QPair<int, int>(rand() % height, rand() % width));
  }
}

void BoardModel::fill()
{
  for (int i = 0; i < height; i++)
  {
    QList<Field*> tmp;
    for (int j = 0; j < width; j++)
    {
      Field *f = NULL;
      if ( bombTiles.contains(QPair<int, int>(i, j)))
      {
        f = new BombField(i, j);
        connect(f, SIGNAL(endGame(bool)), this, SIGNAL(endGame(bool)));
        connect(f, SIGNAL(bombField(int, int)), view, SLOT(bombField(int, int)));
      }
      else 
      {
        f = new EmptyField(i, j);
        connect(f, SIGNAL(updateTile(int, int, int, bool)), view, SLOT(updateTile(int, int, int, bool)));
      }
      connect(f, SIGNAL(revealField(int, int)), this, SLOT(revealField(int, int)));
      connect(f, SIGNAL(flagField(int, int, bool)), view, SLOT(flagField(int, int, bool)));
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

#ifdef QT_DEBUG
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
#endif 
}

void BoardModel::addToDiscoveredFields()
{
  numOfExposedFields++;
  if ((height*width)-numOfExposedFields == numOfMines)
  {
    emit endGame(true);
  }
}

void BoardModel::showAllBombs()
{
  for(int x = 0; x < height; x++)
  {
    for (int y = 0; y < width; y++)
    {
      fields[x][y]->showBomb();
    }
  }
}

void BoardModel::leftClick(int x, int y)
{
  fields[x][y]->revealField();
}

void BoardModel::rightClick(int x, int y)
{
  fields[x][y]->flagField();
}

QString BoardModel::serializeBombs()
{
  QString result;
  for(QPair<int, int> pair : bombTiles)
  {
    result.append(QString("%1:%2 ").arg(pair.first).arg(pair.second));
  }
  return result;
}

void BoardModel::revealAllFields()
{
  for (QList<Field*> list : fields)
  {
    for (Field *field : list)
    {
      field->showField();
    }
  }
}
