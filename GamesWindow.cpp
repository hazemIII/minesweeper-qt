#include "GamesWindow.hpp"
#include <QDebug>

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlField>

#include <QInputDialog>
GamesWindow::GamesWindow(int playerId, QWidget *parent, Qt::WindowFlags f )
{
  db = DataBase::getInstance();
  ui.setupUi(this);
  //connect(ui.view, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(adds(QModelIndex)));
  ui.view->setSelectionMode(QAbstractItemView::SingleSelection);
  ui.view->setSelectionBehavior(QAbstractItemView::SelectRows);
  model = new QSqlTableModel(this, db->dataBase());
  model->setTable("games");
  model->setFilter(QString("player_id = %1").arg(playerId));
  model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  model->select();
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Data"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Czas gry[s]"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Wysokość"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Szerokość"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Ilość bomb"));
  ui.view->setModel(model);
  ui.view->setColumnHidden(0,true);
  ui.view->setColumnHidden(1,true);
  ui.view->setColumnHidden(7,true);
  ui.view->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui.view->resizeColumnsToContents();
  ui.view->horizontalHeader()->setStretchLastSection(true);
}

GamesWindow::~GamesWindow()
{

}


void GamesWindow::adds(QModelIndex index)
{
  emit accepted();
  qDebug() << index;
  QSqlRecord req = model->record(index.row());
  qDebug() << req.field("id").value();
}

