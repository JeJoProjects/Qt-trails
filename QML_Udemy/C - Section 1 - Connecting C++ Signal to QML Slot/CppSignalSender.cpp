#include "CppSignalSender.h"

CppSignalSender::CppSignalSender(QObject* parent) noexcept
  : QObject{ parent }
  , mTimer{ new QTimer{this} }
  , mValue{ 0 }
{
  // the QTimer signal (i.e. QTimer::timeout is connected to the
  // slot(here lambda function), which emits C++ signal(i.e. cppTimer)
  // with the paramter value increased by a one in each 1000 miilisec.
  QObject::connect(mTimer, &QTimer::timeout, [=]() noexcept {
      ++mValue;
      emit cppTimer(QString::number(mValue));
    });
  // period is one sec(1 sec = 1000 milliseconds)
  mTimer->start(1000);
}

void CppSignalSender::cppSlot() noexcept
{
  emit callQml("Information from C++");
}
