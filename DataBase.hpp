#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDateTime>

class DataBase
{
private:
  DataBase(); 
  DataBase(const DataBase &);
  DataBase& operator=(const DataBase&);
  ~DataBase() {}
  QSqlDatabase db;
public:
  static DataBase* getInstance()
  {
    static DataBase instance;
    return &instance;
  }
  QSqlDatabase dataBase();
  void addGame(int playerId, int time, int height, int width, int numOfBombs, QString bombs);
};
#endif
