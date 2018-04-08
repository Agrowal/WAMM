#include "mrpstrukturygateway.h"

mrpStrukturyGateway::mrpStrukturyGateway()
{
    tableName = "MRP_WERSJE_WYROBU";
    makeSql();
}

void mrpStrukturyGateway::find(QString id)
{
    QString sql = "SELECT * FROM mrp_struktury WHERE id_wersji_wyrobu = ";
//    this->query()->query().prepare(sql);
//    this->query()->query().bindValue(1,id);
    sql = sql + "'" + id + "'";
    this->query()->setQuery(sql,this->con()->db());
    qDebug() << this->query()->record(0).value(0);
}

void mrpStrukturyGateway::select()
{

}
