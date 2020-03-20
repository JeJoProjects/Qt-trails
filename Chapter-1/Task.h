#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

private:
    Ui::Task *ui;

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();

};

#endif // TASK_H
