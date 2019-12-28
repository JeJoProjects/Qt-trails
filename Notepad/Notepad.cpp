#include "Notepad.h"
#include "./ui_Notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow{ parent }
    , ui{ new Ui::MainWindow }
    , mCurrentFile{""}
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

Notepad::~Notepad()
{
    delete ui;
}

