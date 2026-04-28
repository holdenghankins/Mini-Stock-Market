#include "market.h"

market::market() {}


void market::addSector(sector* s) {
    sectors.push_back(s); // back is arbitrary location
}


void market::simDay() {
    for (sector* s : sectors) {
        s->simDay();
    }
}
string market::toString() {
    // My documentation would not be truly comprehensive unless I made my hatred of ostringstream known
    ostringstream oss;
    oss << "\n";
    for (sector* s : sectors) {
        oss << s->toString();
    }
    return oss.str();
}