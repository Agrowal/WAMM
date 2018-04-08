#include "wersjewyrobugateway.h"

WersjeWyrobuGateway::WersjeWyrobuGateway()
{
    tableName = "MRP_WERSJE_WYROBU";
    makeSql();
}

void WersjeWyrobuGateway::select()
{
 QString sql = "SELECT * FROM MRP_WERSJE_WYROBU WHERE 1=1 ";
 for(int i = 0; i < m_conditions.size(); ++i){
     QString nextCondition = "and "+m_conditions[i].column+" = '"+m_conditions[i].constraint+"' ";
     sql= sql+nextCondition;
 }
 this->query()->setQuery(sql,this->con()->db());
}
