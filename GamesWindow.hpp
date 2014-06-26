#ifndef GAMESWINDOW_HPP
#define GAMESWINDOW_HPP

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QInputDialog>
#include "ui_Games.h"
#include "DataBase.hpp"
#include "BoardWindow.hpp"
#include "boardModel.hpp"
#include "CheckBoxDelegate.hpp"

class GamesWindow : public QDialog
{
  Q_OBJECT
  
  public:
    GamesWindow(int playerId, QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~GamesWindow();

  private:
    Ui::GamesWin ui;
    DataBase *db;
    QSqlTableModel *model;
    BoardWindow *bWindow;
    BoardModel *bModel;

  private slots:
    void showGame(QModelIndex index);
};

#endif
