#ifndef BOARD_WINDOW_HPP
#define BOARD_WINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLCDNumber>
#include <QList>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QTimer>
#include "NewGameWindow.hpp"
#include "FieldButton.hpp"
#include "boardModel.hpp"

class BoardWindow : public QMainWindow
{
  Q_OBJECT
  private:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *upperLayout;
    QGridLayout *boardLayout;
    QLCDNumber *timeWidget;
    QList<QList<FieldButton*> > buttons;
    QAction *mainMenuAction;
    QObject *parent;
    BoardModel *model;

  public:
    BoardWindow(bool game, QObject *parent = 0);
    ~BoardWindow();
    void prepareButtons(int height, int width);
    void setModel(BoardModel *model);

  public slots:
    void updateTime();
    void bombField(int x, int y);
    void updateTile(int x, int y, int around, bool discovered);
    void flagField(int x, int y, bool flagged);
    void endGame(bool won);

  signals:
    void showMainMenu();
    void leftClick(int, int);
    void rightClick(int, int);

};
#endif
