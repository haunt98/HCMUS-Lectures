#ifndef _MARKET_H
#define _MARKET_H

#include "Sap.h"
#include <vector>

class Market
{
private:
    vector<SAP *> ds_sap;

public:
    void nhap();
    float tongTien();
    ~Market();
};

#endif
