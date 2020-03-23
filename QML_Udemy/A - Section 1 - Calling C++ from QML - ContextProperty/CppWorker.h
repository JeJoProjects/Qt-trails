#ifndef CPPWORKER_H
#define CPPWORKER_H

#include <QObject>

class CppWorker final: public QObject
{
  Q_OBJECT

private:

public:
  explicit CppWorker(QObject *parent = nullptr) noexcept;

  Q_INVOKABLE void regularMethod() const noexcept;
  Q_INVOKABLE QString regularMethodWithReturn(QString, const int) const noexcept;

signals:

public slots:
  void cppSlot() noexcept;
};

#endif // CPPWORKER_H
