
enum FieldStatus
{
  POINT_CLEAR,
  POINT_FLAGGED,
  POINT_DISCOVERED
};

class Field
{
  private:
    bool isMine;
    FieldStatus status;
    unsigned char numOfMinesAround;
    unsigned char countNumOfMinesAround();
  public:
    Field();
    void setStatus(FieldStatus status);
    void setMine(bool isMine);
};

