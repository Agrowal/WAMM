#ifndef MRPSTRUKTURYGATEWAY_H
#define MRPSTRUKTURYGATEWAY_H

#include "datagateway.h"

class mrpStrukturyGateway : public DataGateway
{
    Q_OBJECT
public:
    mrpStrukturyGateway();

    void select();
    void insert();
    void update();
    void deleteData();
    Q_INVOKABLE void find(QString id);
};

#endif // MRPSTRUKTURYGATEWAY_H
