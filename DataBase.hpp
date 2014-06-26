#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDateTime>
#include <QDebug>

class DataBase
{
private:
  DataBase(); 
  DataBase(const DataBase &);
  ~DataBase() {}
  QSqlDatabase db;
public:
  static DataBase* getInstance()
  {
    static DataBase instance;
    return &instance;
  }
  QSqlDatabase dataBase();
  void addGame(int playerId, bool won, int time, int height, int width, int numOfBombs, QString bombs);
};
#endif
