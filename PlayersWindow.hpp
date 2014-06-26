#ifndef PLAYERSWINDOW_HPP
#define PLAYERSWINDOW_HPP

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "ui_Players.h"
#include "DataBase.hpp"
#include "GamesWindow.hpp"

class PlayersWindow : public QDialog
{
  Q_OBJECT
  
  public:
    PlayersWindow(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~PlayersWindow();
    int playerId;
    int exec();
    

  private:
    Ui::PlayersWin ui;
    DataBase *db;
    QSqlTableModel *model;
    GamesWindow *gamesWindow;
    void accept();
  private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void adds(QModelIndex index);
    //void checkValues();
    //void on_addButton_clicked();
};

#endif
