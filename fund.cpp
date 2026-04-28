#include "fund.h"

fund::fund(string name) : security(name, 0) {
}

void fund::setStocks(vector<stock*>* stocks) {
    isFirstDay = 1;
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
    setPrice((largest->getPrice() * 0.4f) + (middle->getPrice() * 0.35f) + (smallest->getPrice() * 0.35f));
    if (isFirstDay) {
        setInitPrice(getPrice());
        isFirstDay = false;
    }
}

void fund::simDay() {
    findThreeStocks();
    calcPrice();
    nextDay();
}