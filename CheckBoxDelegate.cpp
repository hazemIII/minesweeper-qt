#include "CheckBoxDelegate.hpp"

CheckBoxDelegate::CheckBoxDelegate(QObject *parent ):QItemDelegate(parent)
{

}

void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    drawCheck(painter, option, option.rect, index.data().toBool() ? Qt::Checked : Qt::Unchecked);
}
