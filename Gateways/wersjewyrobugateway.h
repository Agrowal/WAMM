#ifndef WERSJEWYROBUGATEWAY_H
#define WERSJEWYROBUGATEWAY_H

#include "datagateway.h"


class WersjeWyrobuGateway : public DataGateway
{
public:
    WersjeWyrobuGateway();

    void select();
    void insert();
    void update();
    void deleteData();
};

#endif // WERSJEWYROBUGATEWAY_H
