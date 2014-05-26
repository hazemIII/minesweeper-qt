#include "ui_NewGameWindow.h"

class NewGameWindow : public QDialog
{
  Q_OBJECT
  
  public:
    NewGameWindow(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~NewGameWindow();
  int height, width, numOfMines;

  private:
    Ui::Dialog ui;
  private slots:
    void checkValues();
    void setMaxMinesCount();
    void on_idiotButton_toggled(bool state);
    void on_beginnerButton_toggled(bool state);
    void on_advancedButton_toggled(bool state);
};
