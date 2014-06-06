#ifndef FIELD_BUTTON_HPP
#define FIELD_BUTTON_HPP

#include <QPushButton>
#include <QMouseEvent>

class FieldButton : public QPushButton
{
  Q_OBJECT
  private:
    int x;
    int y;
  public:
    FieldButton(unsigned int x, unsigned int y, QWidget *parent = 0);
    unsigned int state;
    int minesAround;
  protected:
    void mousePressEvent(QMouseEvent *e);
    //void mouseReleaseEvent(QMouseEvent *e);
  signals:
    void leftClick(int, int);
    void rightClick(int, int);
};

enum 
{
  FIELD_CLEAR,
  FIELD_FLAGGED,
  FIELD_DISCOVERED
};
#endif
