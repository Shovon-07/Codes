#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <counter.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Counter count;
    engine.rootContext()->setContextProperty("backendCount", &count);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Dsa_Project", "Main");

    return QGuiApplication::exec();
}
