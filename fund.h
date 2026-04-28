#ifndef FUND_H_EXISTS
#define FUN_H_EXISTS

#include <list>
#include "sector.h"

class fund : public security {
private:
    stock* largest;
    stock* middle;
    stock* smallest;
    sector* sectorPtr;
    vector<stock*>* stocks;

    void findThreeStocks();
    void calcPrice();
public:
    fund(sector* sectorPtr);
    void setStocks(vector<stock*>* stocks);
    string toString();
};

#endif