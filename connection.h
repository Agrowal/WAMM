#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtCore>
#include <QtSql>
#include "user.h"


class Connection
{
public:
    // Static access method
    static Connection* getConnection();

    User getUser() const;
    User* getUser();
    void setUser(const User &user);

    void openDB();
    void closeDB();

private:
    // Private constructor
    Connection();
    // Instance stored
    static Connection* instance;

    QSqlDatabase m_db;
    User m_user;
};

#endif // CONNECTION_H
