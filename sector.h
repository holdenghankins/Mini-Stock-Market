#ifndef SECTOR_H_EXISTS
#define SECTOR_H_EXISTS

#include "stock.h"
using namespace std;

class sector {
private:
    string name;
    vector<stock*> stocks;
public:
    sector(string name);
    void addStock(stock* s);
    void simDay();
    string toString();
};
#endif