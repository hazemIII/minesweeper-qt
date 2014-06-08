#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class MainWindow: public QMainWindow
{
  Q_OBJECT

  private:
    QWidget *centralWidget;
    QGridLayout *layout;
    QPushButton *newGameButton;
    QPushButton *databaseButton;

  public:
    MainWindow();
    ~MainWindow();

};

#endif
