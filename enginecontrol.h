#ifndef ENGINECONTROL_H
#define ENGINECONTROL_H
#include <QQmlApplicationEngine>
#include <QObject>
#include "connection.h"
#include "user.h"

class EngineControl : public QObject
{
    Q_OBJECT
public:
    explicit EngineControl(QQmlApplicationEngine* engine, QObject *parent = nullptr);
    Q_INVOKABLE void load(QString url);
    Q_INVOKABLE bool login(QString hostName, QString databaseName, QString userName, QString password, QString hostIP= "192.168.1.243", int port = 1521);
    Q_INVOKABLE bool isOpen();
    Q_INVOKABLE QString currentUserName();

signals:

public slots:

private:
    QQmlApplicationEngine* m_engine;

    Connection* m_con = Connection::getConnection();
    User m_currentUser;

};

#endif // ENGINECONTROL_H
