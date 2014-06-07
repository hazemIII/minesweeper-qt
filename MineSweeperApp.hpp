#ifndef MINESWEEPERAPP_HPP
#define MINESWEEPERAPP_HPP

#include <QApplication>
class MineSweeperApp : public QApplication
{

  public:
    MineSweeperApp(int &argc, char **argv);
    ~MineSweeperApp();

};
#endif
