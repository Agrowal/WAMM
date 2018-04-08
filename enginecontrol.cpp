#include "enginecontrol.h"

EngineControl::EngineControl(QQmlApplicationEngine* engine, QObject *parent) : QObject(parent)
{
    m_engine=engine;
}

void EngineControl::load(QString url)
{
    QUrl link = QUrl(url);
    m_engine->load(link);
}

bool EngineControl::login(QString hostName, QString databaseName, QString userName, QString password, QString hostIP, int port)
{
    m_currentUser.setUserName(userName);
    m_currentUser.setUserPass(password);
    return m_con->login(hostIP,port,hostName,databaseName,userName,password);
}

bool EngineControl::isOpen()
{
    qDebug()<< m_con->db()->isOpen();
    return m_con->db()->isOpen();
}

QString EngineControl::currentUserName()
{
    return m_currentUser.userName();
}
