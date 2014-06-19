#include "PlayersWindow.hpp"
#include <QDebug>

#include <QSqlQueryModel>
#include <QSqlQuery>

#include <QInputDialog>
PlayersWindow::PlayersWindow(QWidget *parent, Qt::WindowFlags f )
{
  db = &(DataBase::getInstance());
  ui.setupUi(this);
  //QSqlQueryModel *modal = new QSqlQueryModel();
  //QSqlQuery query(db->datab());
  //query.prepare("select * from players");
  //query.exec();
  //modal->setQuery(query);
  //ui.view->setModel(modal);
  model = new QSqlTableModel(this, db->datab());
  model->setTable("players");
  model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  model->select();
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("NNumOfGames"));
  ui.view->setModel(model);
}

PlayersWindow::~PlayersWindow()
{

}

void PlayersWindow::on_addButton_clicked()
{
  bool ok;
  QString text = QInputDialog::getText(this, "Podaj nazwę gracza","Podaj nazwę gracza", QLineEdit::Normal,
  "Gracz", &ok);
  if (ok && !text.isEmpty())
  {
    QSqlQuery query(db->datab());
    query.prepare("insert into Players values (:name, 0)");
    query.bindValue(":name", text);
    query.exec();
    model->select();
  }
}
