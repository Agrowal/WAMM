#ifndef INDEKSYGATEWAY_H
#define INDEKSYGATEWAY_H

#include "datagateway.h"


class IndeksyGateway : public DataGateway
{
public:
    IndeksyGateway();

    void select();
    void insert();
    void update();
    void deleteData();

};

#endif // INDEKSYGATEWAY_H
