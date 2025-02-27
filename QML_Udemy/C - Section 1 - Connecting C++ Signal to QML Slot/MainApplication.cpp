#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "CppSignalSender.h"

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  // ContextProperty
  CppSignalSender sender{};
  engine.rootContext()->setContextProperty("CppSignalSender", &sender);

  const QUrl url(QStringLiteral("qrc:/Main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
