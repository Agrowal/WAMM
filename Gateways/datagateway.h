#ifndef DATAGATEWAY_H
#define DATAGATEWAY_H

#include <QObject>
#include "connection.h"
#include "sqlquerymodel.h"


//Base class for Gateways
class DataGateway: public QObject
{
    Q_OBJECT
    Q_PROPERTY(SqlQueryModel* resultSet READ query NOTIFY resultSetChanged)

    struct condition{
        QString column;
        QString constraint;
    };

public:
    DataGateway(QObject *parent = nullptr);

    Q_INVOKABLE virtual void select() = 0;
    //virtual void insert() = 0;
    //virtual void update() = 0;
    //virtual void deleteData() = 0;

    SqlQueryModel *query() const;
    Connection *con() const;

    void makeSql();
    void addContion(const QString column, const QString constraint);

protected:
    QVector<condition> m_conditions;
    QString tableName;
    QString sql;

private:
    SqlQueryModel* m_query = new SqlQueryModel(0);
    Connection* m_con = Connection::getConnection();

signals:
    void resultSetChanged();
};

#endif // DATAGATEWAY_H
