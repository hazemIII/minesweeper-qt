#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

#include "MineSweeperApp.hpp"

class MainWindow: public QMainWindow
{
  Q_OBJECT

  private:
    QWidget *centralWidget;
    QGridLayout *layout;
    QPushButton *newGameButton;
    QPushButton *databaseButton;
    MineSweeperApp *app;

  public:
    MainWindow();
    ~MainWindow();

};

#endif
