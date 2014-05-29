#ifndef FIELD_HPP
#define FIELD_HPP
enum FieldStatus
{
  POINT_CLEAR,
  POINT_FLAGGED,
  POINT_DISCOVERED
};

class Field
{
  private:
    FieldStatus status;
    unsigned char countNumOfMinesAround();
  public:
    Field();
    bool isMine;
    void setStatus(FieldStatus status);
    void setMine(bool isMine);
    unsigned char numOfMinesAround;
};
#endif
