#include "fund.h"

fund::fund(sector* sectorPtr) {
    this->sectorPtr = sectorPtr;
}

void fund::setStocks(vector<stock*>* stocks) {
    this->stocks = stocks;
}

void fund::findThreeStocks() {
    largest = middle = smallest = nullptr;

    for (stock* s : *stocks) {
        float price = s->getPrice();
        if (!largest || price >= largest->getPrice()) {
            smallest = middle;
            middle = largest;
            largest = s;
        } else if (!middle || price >= middle->getPrice()) {
            smallest = middle;
            middle = s;
        } else if (!smallest || price >= smallest->getPrice()) {
            smallest = s;
        }
    }
}

void fund::calcPrice() {
    setPrice((largest->getPrice() * 0.4f) + (middle->getPrice() * 35) + (smallest->getPrice() * 35));
    nextDay();
}

string fund::toString() {
    calcPrice();
    ostringstream oss;
    oss << getName() << "(" << sectorPtr->getName() << ") : $" << getPrice()
        << " | " << getChange(1)  << "% today" << ", " << getChange(5)  << "% week"
        << ", " << getChange(20) << "% month" << ", " << getTotalChange() << "% all time";
}