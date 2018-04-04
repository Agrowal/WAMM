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
    m_db.setHostName("192.168.1.243:1521/TEST");
    m_db.setDatabaseName("Flowair test");
    m_db.setUserName("GMICKOWSKI");
    m_db.setPassword("GMi2016!");
    m_db.setPort(1521);
    m_db.open();

}

User Connection::getUser() const
{
    return m_user;
}

User *Connection::getUser()
{
    return &m_user;
}

void Connection::setUser(const User &user)
{
    m_user = user;
}

void Connection::openDB()
{
    m_db.setUserName(m_user.userName());
    m_db.setPassword(m_user.userPass());
    m_db.open();
}
