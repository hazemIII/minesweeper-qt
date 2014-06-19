#include "DataBase.hpp"
#include <QDebug>

DataBase::DataBase()
{
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("saper.db");
    if (db.open()) {
        QSqlQuery query(db);
        qDebug() << query.exec("CREATE TABLE IF NOT EXISTS players ('Name' VARCHAR(50), 'NumOfGames' SMALLINT(10))");
    } else {
        qDebug() << "DB Nao aberto.";
    }
    //db.close();

}

QSqlDatabase DataBase::datab()
{
  return db;
}
