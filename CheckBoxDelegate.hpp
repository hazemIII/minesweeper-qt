#include <QItemDelegate>
#include <QPainter>
#include <QStyle>

class CheckBoxDelegate: public QItemDelegate
{
  Q_OBJECT
  public:
    CheckBoxDelegate(QObject *parent = 0);
    void paint( QPainter *painter,
        const QStyleOptionViewItem &option,
        const QModelIndex &index ) const;
};


