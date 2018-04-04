#include "user.h"

User::User()
{

}

QString User::userName() const
{
    return m_userName;
}

void User::setUserName(const QString &userName)
{
    m_userName = userName;
}

QString User::userPass() const
{
    return m_userPass;
}

void User::setUserPass(const QString &userPass)
{
    m_userPass = userPass;
}
