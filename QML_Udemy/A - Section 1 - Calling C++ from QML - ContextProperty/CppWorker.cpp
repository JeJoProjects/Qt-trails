#include "CppWorker.h"

#include <QDebug>

#include <utility>

CppWorker::CppWorker(QObject *parent) noexcept
  : QObject{parent }
{}

void CppWorker::regularMethod() const noexcept
{
  qDebug() << "Called the CppWorker::regularMethod() method.";
}

QString CppWorker::regularMethodWithReturn(QString name, const int age) const noexcept
{
  return QString{ std::move(name) + " :" + QString::number(age) + " years old" };
}

void CppWorker::cppSlot() noexcept
{
  qDebug() << "Called the CppWorker::cppSlot() slot.";
}
