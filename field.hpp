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
    bool flagged;
  public:
    Field(int x, int y);
    virtual void revealField();
    int numOfMinesAround;
    bool discovered;
    void flagField();
    void showBomb();

  signals:
    void revealFields(int x, int y);
    void utile(int x, int y, bool mine, int around, bool checked);
    void flagField(int x, int y, bool flagged);
    void addToDiscoveredFields();

    void updateTile(int, int, int, bool);
};

class BombField : public Field
{
  Q_OBJECT

  public:
    BombField(int x, int y);
    void revealField();
    void showBomb();
  signals:
    void revealField(int x, int y);
    void endGame(bool);

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
