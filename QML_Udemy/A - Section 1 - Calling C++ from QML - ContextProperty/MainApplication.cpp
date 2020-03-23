#include <QGuiApplication>
#include <QQmlContext> // brings C++ powers to QML
#include <QQmlApplicationEngine>

#include "CppWorker.h"


int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  // Expose the instance of the class as ContextProperty
  CppWorker worker{};
  engine.rootContext()->setContextProperty("Worker", &worker);

  const QUrl url(QStringLiteral("qrc:/Main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
