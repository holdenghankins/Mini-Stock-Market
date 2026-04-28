#ifndef SECTOR_H_EXISTS
#define SECTOR_H_EXISTS

#include "stock.h"
#include "fund.h"
using namespace std;

class sector {
private:
    string name;

    // Stores stocks in vector because I am planning on making a UI in my spare time and need o(1) access to stocks
    vector<stock*> stocks;
    fund* fundPtr;
public:
    sector(string name, string fundName);
    string getName();
    void addStock(stock* s);

    // Itterates through each stock before hitting the index fund
    void simDay();

    // Special print to include a header and fund
    string toString();
};
#endif