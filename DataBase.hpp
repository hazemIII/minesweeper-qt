#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QSqlDatabase>
#include <QSqlQuery>

class DataBase
{
private:
  DataBase(); 
  DataBase(const DataBase &);
  DataBase& operator=(const DataBase&);
  ~DataBase() {}
  QSqlDatabase db;
public:
  static DataBase& getInstance()
  {
    static DataBase instance;
    return instance;
  }
  QSqlDatabase datab();
};
#endif
