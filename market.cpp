#include "market.h"

market::market() {
}


void market::addSector(sector* s) {
    sectors.push_back(s);
}


void market::simDay() {
    for (sector* s : sectors) {
        s->simDay();
    }
}
string market::toString() {
    ostringstream oss;
    oss << "\n";
    for (sector* s : sectors) {
        oss << s->toString();
    }
    return oss.str();
}