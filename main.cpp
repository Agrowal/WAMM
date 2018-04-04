#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "connection.h"
#include "sqlquerymodel.h"
#include "enginecontrol.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    EngineControl* engineControl = new EngineControl(&engine);
    engine.rootContext()->setContextProperty("myEngineControl", engineControl);


    Connection* db = Connection::getConnection();

    SqlQueryModel *model = new SqlQueryModel(0);
    model->setQuery("select i.NUMER_KATALOGOWY, i.INDEKS from INDEKSY i where rownum <= 20");
    engine.rootContext()->setContextProperty("myModel", model);


    engine.load(QUrl(QStringLiteral("qrc:/LoginDialog.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
