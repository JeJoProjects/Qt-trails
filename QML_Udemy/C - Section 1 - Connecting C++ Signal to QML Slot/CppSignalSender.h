#ifndef CPPSIGNALSENDER_H
#define CPPSIGNALSENDER_H

#include <QObject>
#include <QTimer>

class CppSignalSender final: public QObject
{
  Q_OBJECT

private:
  QTimer* mTimer;
  int mValue;

public:
  explicit CppSignalSender(QObject *parent = nullptr) noexcept;

signals:
  void callQml(QString arg);
  void cppTimer(QString value);

public slots:
  // following slot again emit the C++ class signal(i.e. callQml())
  // which will be cought by the QML latter, if we have respective
  // "Connections" componet in the QML file.
  void cppSlot() noexcept;
};

#endif // CPPSIGNALSENDER_H
