#include "DataBase.hpp"
#include <QDebug>

DataBase::DataBase()
{
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("saper.db");
    if (db.open()) {
        QSqlQuery query(db);
        query.exec("CREATE TABLE players (id INTEGER PRIMARY KEY, Name TEXT, NumOfGames INT)");
        query.exec("CREATE TABLE games (id INTEGER PRIMARY KEY, player_id INTEGER, timestamp INTEGER, time INTEGER, height INTEGER, width INTEGER, numOfBombs INTEGER, serializedBombs TEXT)");
    } else {
      qCritical() << "Nie można utworzyć bazy danych!";
    }

}

QSqlDatabase DataBase::dataBase()
{
  return db;
}
