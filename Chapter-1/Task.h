#ifndef TASK_H
#define TASK_H

// Qt headers
#include <QWidget>
#include <QString>

// C++  headers

// forward declarations
namespace Ui {
  class Task;
}

class Task final : public QWidget
{
  Q_OBJECT

private:
  Ui::Task *ui;

public:
  // constructors and destructors
  explicit Task(QString, QWidget *parent = nullptr) noexcept;
  ~Task() noexcept;
  Q_DISABLE_COPY_MOVE(Task);

  void setName(QString) noexcept;
  QString name() const noexcept;
  bool isCompleted() const noexcept;

};

#endif // TASK_H
