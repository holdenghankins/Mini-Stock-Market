#ifndef MARKET_H_EXISTS
#define MARKET_H_EXISTS

#include <list>
#include "sector.h"

class market {
private:
    list<sector*> sectors;
public:
    market();
    void addSector(sector* s);
    void simDay();
    string toString();
};
#endif