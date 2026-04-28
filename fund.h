#ifndef FUND_H_EXISTS
#define FUND_H_EXISTS

#include <vector>
#include <list>
#include "stock.h"

class fund : public security {
private:
    stock* largest;
    stock* middle;
    stock* smallest;
    vector<stock*>* stocks;
    int isFirstDay;

    void findThreeStocks();
    void calcPrice();
public:
    fund(string name);
    void setStocks(vector<stock*>* stocks);
    void simDay();
};
#endif