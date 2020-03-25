// Own headers
#include "MainWindow.h"
#include "ui_mainwindow.h"

// Qt headers

// C++ headers

// forward declarations


MainWindow::MainWindow(QWidget *parent) noexcept
  : QMainWindow{ parent }
  , ui{ new Ui::MainWindow }
{
    this->ui->setupUi(this);
}

MainWindow::~MainWindow() noexcept
{
    delete ui;
}
