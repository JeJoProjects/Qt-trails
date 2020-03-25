#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt headers
#include <QMainWindow>
#include <QVector>
#include "Task.h"

// C++  headers

// forward declarations
namespace Ui {
    class MainWindow;
}


class MainWindow final : public QMainWindow
{
    /*This macro allows the class to define its own signals/slots
     * and more globally Qt's meta-object system.
     */
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QVector<Task*> mTasks;

public:
    // constructors and destructors
    explicit MainWindow(QWidget *parent = nullptr) noexcept;
    ~MainWindow() noexcept;
    Q_DISABLE_COPY_MOVE(MainWindow);

public slots:
    void addTask() noexcept;


};

#endif // MAINWINDOW_H

