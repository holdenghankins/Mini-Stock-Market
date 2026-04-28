#include "sector.h"

sector::sector(string name, string fundName) {
    this->name = name;
    fundPtr = new fund(fundName);

    // Sets stocks in fund to local stocks so changes apply in both places
    fundPtr->setStocks(&stocks);
}

string sector::getName() {
    return name;
}

void sector::addStock(stock* s) {
    stocks.push_back(s); // back is arbitrary
}

void sector::simDay() {
    // Itterate through stocks
    for (int i = 0; i < stocks.size(); i++) {
        stocks.at(i)->simDay();
    }

    // Sim on funPtr
    fundPtr->simDay();
}

string sector::toString() {
    ostringstream oss;

    // Header
    oss << "---" << name << "---\n";

    // Stocks
    for (int i = 0; i < stocks.size(); i++) {
        oss << stocks.at(i)->toString() << "\n";
    }

    // Fund
    oss << fundPtr->toString() << "\n\n";
    
    return oss.str();
}