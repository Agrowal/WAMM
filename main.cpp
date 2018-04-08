#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "connection.h"
#include "sqlquerymodel.h"
#include "enginecontrol.h"
#include "gateways\indeksygateway.h"
#include "Gateways/wersjewyrobugateway.h"
#include "Gateways/mrpstrukturygateway.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    EngineControl* engineControl = new EngineControl(&engine);
    engine.rootContext()->setContextProperty("myEngineControl", engineControl);

    qDebug() << "IS DB OPEN: " << engineControl->login("TEST","Flowair test","GMICKOWSKI","GMi2016!");

    IndeksyGateway *indeksyBrama = new IndeksyGateway();
    indeksyBrama->select();
    engine.rootContext()->setContextProperty("indeksyBrama",indeksyBrama);

    WersjeWyrobuGateway *wersjeWyrobuBrama = new WersjeWyrobuGateway;
    wersjeWyrobuBrama->select();
    engine.rootContext()->setContextProperty("wersjeWyrobuBrama",wersjeWyrobuBrama);

    mrpStrukturyGateway *mrpStrukturyBrama = new mrpStrukturyGateway;
    engine.rootContext()->setContextProperty("mrpStrukturyBrama",mrpStrukturyBrama);

    engine.load(QUrl(QStringLiteral("qrc:/LoginDialog/LoginDialog.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
