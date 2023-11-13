#include <QCommandLineParser>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>

#include <iostream>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QCoreApplication::setApplicationName("App name");
    QCoreApplication::setApplicationVersion("1.0.0B1");

    app.setOrganizationName("AVMAP");
    app.setOrganizationDomain("https://www.avmap.it");

    QCommandLineParser parser;
    parser.setApplicationDescription("Application description");\

    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption disbleGuiOption(QStringList() << "n" << "no-gui",
                                       QCoreApplication::translate("No GUI", "disable gui (disabled by default)"));
    parser.addOption(disbleGuiOption);

    parser.process(app);

    bool enableGui = !parser.isSet(disbleGuiOption);

    if(enableGui)
    {
        QQmlApplicationEngine engine;

        const QUrl url(QStringLiteral("qrc:/main.qml"));
        QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
        engine.load(url);

        //GUI EXECUTION
        return app.exec();
    }
    else
    {
        //NO GUI EXECUTION
        return 0;
    }
}
