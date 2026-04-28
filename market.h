#ifndef MARKET_H_EXISTS
#define MARKET_H_EXISTS

#include <list>
#include "sector.h"

class market {
private:
    // Saves everything in their sectors in a linked list
    list<sector*> sectors;
public:
    market();
    void addSector(sector* s);

    // Itterates through all sectors, calling their respective simDays
    // This by proxy makes a call for every stock, plus the index fund
    void simDay();
    string toString();
};
#endif