#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtCore>
#include <QtSql>


class Connection
{
public:
    // Static access method
    static Connection* getConnection();

    QSqlDatabase* db();
    bool login(QString hostIP, int port, QString hostName, QString databaseName, QString userName, QString password);

private:
    // Private constructor
    Connection();
    // Instance stored
    static Connection* instance;
    
    QString connectionString();


    QSqlDatabase m_db;
    QString m_hostIP;
    int m_port;
    QString m_hostName;
    QString m_databaseName;
    QString m_userName;
    QString m_password;
    
};

#endif // CONNECTION_H
