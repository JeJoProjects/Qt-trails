#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator final : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = {});
    ~Calculator();

private:
    Ui::Calculator *ui;

};

#endif // CALCULATOR_H
