#include "Notepad.h"
#include "./ui_Notepad.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{ parent }
    , ui{ new Ui::MainWindow }
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

