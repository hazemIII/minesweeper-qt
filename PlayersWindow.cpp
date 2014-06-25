#include "PlayersWindow.hpp"
#include <QDebug>

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlField>

#include <QInputDialog>
PlayersWindow::PlayersWindow(QWidget *parent, Qt::WindowFlags f )
{
  gamesWindow = nullptr;
  db = DataBase::getInstance();
  ui.setupUi(this);
  connect(ui.view, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(adds(QModelIndex)));
  //connect(ui.view, SIGNAL(doubleClicked(QModelIndex)), this, SIGNAL(accepted()));
  ui.view->setSelectionMode(QAbstractItemView::SingleSelection);
  ui.view->setSelectionBehavior(QAbstractItemView::SelectRows);
  model = new QSqlTableModel(this, db->dataBase());
  model->setTable("players");
  model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  model->select();
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nazwa Gracza"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ilość gier"));
  ui.view->setModel(model);
  ui.view->setColumnHidden(0,true);
  ui.view->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui.view->resizeColumnsToContents();
  ui.view->horizontalHeader()->setStretchLastSection(true);
}

PlayersWindow::~PlayersWindow()
{
  if (gamesWindow != nullptr)
  {
    delete gamesWindow;
  }
}

void PlayersWindow::on_addButton_clicked()
{
  bool ok;
  QString text = QInputDialog::getText(this, "Podaj nazwę gracza","Podaj nazwę gracza", QLineEdit::Normal,
  "Gracz", &ok);
  if (ok && !text.isEmpty())
  {
    QSqlQuery query(db->dataBase());
    query.prepare("insert into Players values (NULL, :name, 0)");
    query.bindValue(":name", text);
    query.exec();
    model->select();
  }
}

void PlayersWindow::on_deleteButton_clicked()
{
  QItemSelectionModel *selectedModel = ui.view->selectionModel();
  if(selectedModel->hasSelection()) {
    model->removeRows(ui.view->currentIndex().row(),1);
    model->submitAll();
    model->select();
  }
  delete selectedModel;
}

void PlayersWindow::adds(QModelIndex index)
{
  emit accepted();
  qDebug() << index;
  QSqlRecord req = model->record(index.row());
  qDebug() << req.field("id").value();
  if (gamesWindow != nullptr)
  {
    delete gamesWindow;
  }
  gamesWindow = new GamesWindow(req.field("id").value().toInt());
  gamesWindow->exec();
}

void PlayersWindow::accept()
{
  QItemSelectionModel *selectedModel = ui.view->selectionModel();
  qDebug() << selectedModel;
  if(selectedModel->hasSelection()) {
    QSqlRecord req = model->record(ui.view->currentIndex().row());
    playerId = req.field("id").value().toInt();
    QDialog::accept();
  }
}
