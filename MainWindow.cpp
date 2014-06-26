#include "MainWindow.hpp"

MainWindow::MainWindow()
{
  centralWidget = new QWidget(this);
  this->setCentralWidget(centralWidget);
  layout = new QGridLayout();
  centralWidget->setLayout(layout);
  newGameButton = new QPushButton("Nowa gra.");
  databaseButton = new QPushButton("Baza danych.");
  layout->addWidget(databaseButton);
  layout->addWidget(newGameButton);
  app = new MineSweeperApp();
  connect(newGameButton, SIGNAL(clicked()), app, SLOT(newGame()));
  connect(databaseButton, SIGNAL(clicked()), app, SLOT(showDataBase()));
  connect(app, SIGNAL(hideMainWindow()), this, SLOT(hide()));
  connect(app, SIGNAL(showMainMenu()), this, SLOT(show()));
  this->show();
}

MainWindow::~MainWindow()
{
  delete databaseButton;
  delete newGameButton;
  delete centralWidget;
  delete app;
}



