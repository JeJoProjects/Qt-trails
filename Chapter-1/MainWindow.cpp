// own headers
#include "MainWindow.h"
#include "ui_MainWindow.h"

// Qt headers
#include <QDebug>
#include <QInputDialog>

// C++  headers

MainWindow::MainWindow(QWidget *parent) noexcept
    : QMainWindow{ parent }
    , ui{ new Ui::MainWindow }
    , mTasks{}
{
    ui->setupUi(this);
    // basic
    // connect(ui->addTaskButton, &QPushButton::clicked,
    //         QApplication::instance(), &QApplication::quit);
    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
}

MainWindow::~MainWindow() noexcept
{
    delete ui;
}

void MainWindow::addTask() noexcept
{
  bool okay{false};
  const QString name = QInputDialog::getText(
        this, tr("Add task"), tr("Task name"),
        QLineEdit::Normal, tr("Untitled task"), &okay);

  if(okay && !name.isEmpty())
  {
      qDebug() << "Adding new task\n";
      mTasks.push_back(new Task{name});
      // the ownership of the newly created task is transferred to tasksLayout
      this->ui->tasksLayout->addWidget(mTasks.back());
  }
}
