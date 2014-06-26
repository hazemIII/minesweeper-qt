#include "DataBase.hpp"
#include <QDebug>

DataBase::DataBase()
{
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("saper.db");
    if (db.open()) {
        QSqlQuery query(db);
        query.exec("CREATE TABLE players (id INTEGER PRIMARY KEY, Name TEXT, NumOfGames INT)");
        query.exec("CREATE TABLE games (id INTEGER PRIMARY KEY, player_id INTEGER, won BOOLEAN, timestamp INTEGER, time INTEGER, height INTEGER, width INTEGER, numOfBombs INTEGER, serializedBombs TEXT)");
    } else {
      qCritical() << "Nie można utworzyć bazy danych!";
    }

}

QSqlDatabase DataBase::dataBase()
{
  return db;
}

void DataBase::addGame(int playerId, int time, int height, int width, int numOfBombs, QString bombs)
{
  QDateTime timestamp(QDateTime::currentDateTime());
  QSqlQuery query(db);
  query.prepare("INSERT INTO games VALUES (NULL, :id, :timestamp, :time, :height, :width, :numOfBombs, :bombs);");
  query.bindValue(":id", playerId);
  query.bindValue(":timestamp", timestamp.toString("HH:mm d/M/yy"));
  query.bindValue(":time", time);
  query.bindValue(":height", height);
  query.bindValue(":width", width);
  query.bindValue(":numOfBombs", numOfBombs);
  query.bindValue(":bombs", bombs);
  query.exec();
  query.prepare("UPDATE players SET NumOfGames = NumOfGames + 1 WHERE id = ?");
  query.bindValue(0, playerId);
  query.exec();
}
