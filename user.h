#ifndef USER_H
#define USER_H

#include <QtCore>


class User
{
public:
    User();

    QString userName() const;
    void setUserName(const QString &userName);

    QString userPass() const;
    void setUserPass(const QString &userPass);

private:
    QString m_userName;
    QString m_userPass;
};

#endif // USER_H
