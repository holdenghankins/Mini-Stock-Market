#ifndef SECTOR_H_EXISTS
#define SECTOR_H_EXISTS

#include "stock.h"
#include "fund.h"
using namespace std;

class sector {
private:
    string name;
    vector<stock*> stocks;
    fund* fundPtr;
public:
    sector(string name, string fundName);
    string getName();
    void addStock(stock* s);
    void simDay();
    string toString();
};
#endif