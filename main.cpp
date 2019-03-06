#include "SimpleListModel.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    auto rootContext = engine.rootContext();
    SimpleListModel nameListModel;

    qmlRegisterType<Container>("name.holyoak", 1, 0, "Container");

    rootContext->setContextProperty("nameModel",
                                     &nameListModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
