#ifndef FIELD_HPP
#define FIELD_HPP
#include <QObject>
enum FieldStatus
{
  POINT_CLEAR,
  POINT_FLAGGED,
  POINT_DISCOVERED
};

class Field : public QObject
{
  Q_OBJECT
  protected:
    int x;
    int y;
  public:
    Field(int x, int y);
    virtual void revealField();
    int numOfMinesAround;
    bool discovered;
    void flagField();

  signals:
    void revealFields(int x, int y);
    void utile(int x, int y, bool mine, int around, bool checked);
    void flagField(int x, int y);
};

class BombField : public Field
{
  Q_OBJECT

  public:
    BombField(int x, int y);
    void revealField();
  signals:
    void revealField(int x, int y);
    void endGame();

};

class EmptyField : public Field
{
  Q_OBJECT

  public:
    EmptyField(int x, int y);
    void revealField();
  signals:
    void revealField(int x, int y);
    void UTILE(int, int, int);
};

#endif
