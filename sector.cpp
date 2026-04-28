#include "sector.h"

sector::sector(string name) {
    this->name = name;
}

string sector::getName() {
    return name;
}

void sector::addStock(stock* s) {
    stocks.push_back(s);
}

void sector::simDay() {
    for (int i = 0; i < stocks.size(); i++) {
        stocks.at(i)->simDay();
    }
}

string sector::toString() {
    ostringstream oss;
    for (int i = 0; i < stocks.size(); i++) {
        oss << stocks.at(i)->toString();
    }
}