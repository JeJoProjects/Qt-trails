#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDevice>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Notepad final : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = {});
    ~Notepad();

private:
    Ui::MainWindow *ui;
    QString mCurrentFile;
};

#endif // MAINWINDOW_H
