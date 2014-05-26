#include <QPushButton>
#include <QMouseEvent>

class FieldButton : public QPushButton
{
  Q_OBJECT
  private:
    unsigned int state;
  public:
    FieldButton(QWidget *parent = 0);
  protected:
    void mousePressEvent(QMouseEvent *e);
    //void mouseReleaseEvent(QMouseEvent *e);
};
