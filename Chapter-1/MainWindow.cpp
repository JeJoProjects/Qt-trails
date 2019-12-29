// own headers
#include "MainWindow.h"
#include "ui_MainWindow.h"

// Qt headers
#include <QDebug>

// C++  headers
#include <chrono>
#include <thread>

static std::size_t count{0};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{ parent }
    , ui{ new Ui::MainWindow }
{
    ui->setupUi(this);
    // basic
    // connect(ui->addTaskButton, &QPushButton::clicked,
    //         QApplication::instance(), &QApplication::quit);
    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()  const noexcept
{
    if(count < 3)
    {
        qDebug() << "The User clicked on the button for " << ++count << " time!";
        if(count == 3) // third time coonect with the other slot(quit)
        {
            connect(ui->addTaskButton, &QPushButton::clicked,
                    QApplication::instance(), &QApplication::quit);
        }
    }
    else
    {
        qDebug() << "Going to exit soon...";
        short sec{3};
        while(sec)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            qDebug() << sec-- ;
        }

    }
}
