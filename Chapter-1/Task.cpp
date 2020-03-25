// own headers
#include "Task.h"
#include "ui_Task.h"

// Qt headers

// C++  headers
#include <utility> // std::move


Task::Task(QString name, QWidget *parent) noexcept
  : QWidget{ parent }
  , ui{ new Ui::Task }
{
  this->ui->setupUi(this);
  this->setName(std::move(name));
}

Task::~Task() noexcept
{
  delete ui;
}

void Task::setName(QString name) noexcept
{
  this->ui->checkBox->setText(std::move(name));
}

QString Task::name() const noexcept
{
  return this->ui->checkBox->text();
}

bool Task::isCompleted() const noexcept
{
  return this->ui->checkBox->isChecked();
}
