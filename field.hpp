#ifndef FIELD_HPP
#define FIELD_HPP
#include <QObject>

class Field : public QObject
{
  Q_OBJECT
  protected:
    int x;
    int y;
    bool flagged;
    bool discovered;
  public:
    Field(int x, int y);
    int numOfMinesAround;
    virtual void revealField();
    void flagField();
    virtual void showBomb();
    virtual void showField() {};

  signals:
    void revealFields(int x, int y);
    void flagField(int x, int y, bool flagged);
    void addToDiscoveredFields();

    void updateTile(int, int, int, bool);
    void bombField(int, int);
};

class BombField : public Field
{
  Q_OBJECT

  public:
    BombField(int x, int y);
    void revealField();
    void showBomb();
    void showField();
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
    void showField();
  signals:
    void revealField(int x, int y);
};

#endif
