#include "connection.h"

/* Null, because instance will be initialized on demand. */
Connection* Connection::instance = 0;

Connection* Connection::getConnection()
{
    if (instance == 0)
    {
        instance = new Connection();
    }

    return instance;
}


Connection::Connection()
{
    m_db = QSqlDatabase::addDatabase("QODBC");
}

QString Connection::connectionString()
{
    return m_hostIP+":"+QString::number(m_port)+"/"+m_hostName;
}

QSqlDatabase* Connection::db()
{
    return &m_db;
}

bool Connection::login(QString hostIP, int port, QString hostName, QString databaseName, QString userName, QString password)
{
    m_hostIP = hostIP;
    m_port = port;
    m_hostName = hostName;
    QString conString = connectionString();

    m_db.setHostName(conString);
    m_db.setDatabaseName(databaseName);
    m_db.setUserName(userName);
    m_db.setPassword(password);
    m_db.setPort(port);

//    m_db.setHostName("192.168.1.243:1521/TEST");
//    m_db.setDatabaseName("Flowair test");
//    m_db.setUserName("GMICKOWSKI");
//    m_db.setPassword("GMi2016!");
//    m_db.setPort(1521);

//    qDebug() << m_db.hostName() << m_db.databaseName() << m_db.userName() << m_db.password() << m_db.port();
    return m_db.open();
}
