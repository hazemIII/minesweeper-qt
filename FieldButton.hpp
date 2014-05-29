#ifndef FIELD_BUTTON_HPP
#define FIELD_BUTTON_HPP

#include <QPushButton>
#include <QMouseEvent>

class FieldButton : public QPushButton
{
  Q_OBJECT
  private:
    unsigned int state;
    int x;
    int y;
    int minesAround;
  public:
    FieldButton(unsigned int x, unsigned int y, QWidget *parent = 0);
  protected:
    void mousePressEvent(QMouseEvent *e);
    //void mouseReleaseEvent(QMouseEvent *e);
  signals:
    void KLIK(int, int);
};

enum 
{
  FIELD_CLEAR,
  FIELD_FLAGGED,
  FIELD_DISCOVERED
};
#endif
