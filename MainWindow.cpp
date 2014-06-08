#include "MainWindow.hpp"

MainWindow::MainWindow()
{
  centralWidget = new QWidget(this);
  layout = new QGridLayout();
  centralWidget->setLayout(layout);
  newGameButton = new QPushButton("Nowa gra.");
  layout->addWidget(newGameButton);
  databaseButton = new QPushButton("Baza danych.");
  layout->addWidget(databaseButton);
}

MainWindow::~MainWindow()
{
  delete databaseButton;
  delete newGameButton;
  delete centralWidget;
  delete layout;
}
