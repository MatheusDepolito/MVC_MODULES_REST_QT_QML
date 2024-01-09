#include "Controllers/MainController.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //app.setWindowIcon(QIcon(":/Icones/"));
    app.setOrganizationName("Anglo");
    app.setOrganizationDomain("Anglo");
    app.setApplicationName("Dashboard Educacional");

    QQmlApplicationEngine engine;

    MainController mc;
    mc.autenticar("mat","12121212");

    mc.solicitarConsultaTurmas("2023");


    qmlRegisterSingletonType<MainController>("MainController", 1, 0, "MainController", [&](QQmlEngine *, QJSEngine *)-> QObject*{
        return &mc;
    });



    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("DashboardEducacional", "Main");

    return app.exec();
}
