#include "Calculator.h"
#include "ui_Calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow{ parent }
    , ui{ new Ui::Calculator }
{
    this->ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

