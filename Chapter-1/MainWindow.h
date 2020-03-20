#pragma once

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    /*This macro allows the class to define its own signals/slots
     * and more globally Qt's meta-object system.
     */
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addTask() const noexcept;


};

