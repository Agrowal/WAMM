#include "datagateway.h"


DataGateway::DataGateway(QObject *parent): QObject(parent)
{
}

SqlQueryModel *DataGateway::query() const
{
    return m_query;
}

Connection *DataGateway::con() const
{
    return m_con;
}

void DataGateway::makeSql()
{
    sql = "SELECT * FROM "+tableName+" WHERE 1=1";
}

void DataGateway::addContion(const QString column, const QString constraint)
{
    condition newCondition;
    newCondition.column = column;
    newCondition.constraint = constraint;
    m_conditions.append(newCondition);
}

