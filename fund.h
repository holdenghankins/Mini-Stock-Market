#ifndef FUND_H_EXISTS
#define FUND_H_EXISTS

#include <vector>
#include <list>
#include "stock.h"

class fund : public security {
private:
    // Saves the top 3 stocks in a list of stocks
    // Will use them later for calculating price
    stock* largest;
    stock* middle;
    stock* smallest;
    vector<stock*>* stocks;

    // Used to transfer price for history on first day
    int isFirstDay;

    // Price is determined by (40% largest, 35% 2nd largest, 25% 3rd largest) to represent a diverse fund
    void findThreeStocks();
    void calcPrice();
public:
    fund(string name);

    // Adds stocks using the preexisting vector in the sector class
    void setStocks(vector<stock*>* stocks);

    // calcs, saves fund, moves day
    void simDay();
};
#endif