#include "indeksygateway.h"

#define GET_VARIABLE_NAME(Variable) (#Variable)

IndeksyGateway::IndeksyGateway()
{
    tableName = "INDEKSY";
    makeSql();
}

void IndeksyGateway::select()
{
 //QString sql = "SELECT INDEKS_CZESCI, NUMER_KATALOGOWY, INDEKS FROM indeksy WHERE 1=1 ";
 for(int i = 0; i < m_conditions.size(); ++i){
     QString nextCondition = "and "+m_conditions[i].column+" = '"+m_conditions[i].constraint+"' ";
     sql= sql+nextCondition;
 }
 this->query()->setQuery(sql,this->con()->db());
 //qDebug() << this->query()->record(0).value(0);
}
