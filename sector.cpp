#include "sector.h"

sector::sector(string name, string fundName) {
    this->name = name;
    fundPtr = new fund(fundName);
    fundPtr->setStocks(&stocks);
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
    fundPtr->simDay();
}

string sector::toString() {
    ostringstream oss;
    oss << "---" << name << "---\n";
    for (int i = 0; i < stocks.size(); i++) {
        oss << stocks.at(i)->toString() << "\n";
    }
    oss << fundPtr->toString() << "\n\n";
    return oss.str();
}