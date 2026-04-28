#include "fund.h"

fund::fund(string name) : security(name, 0) {
    // Because the initial price is 0, I have to do the isFirstDay calculation
}

void fund::setStocks(vector<stock*>* stocks) {
    isFirstDay = 1;
    this->stocks = stocks;
}

void fund::findThreeStocks() {
    // Erase previous values for cleanliness
    largest = middle = smallest = nullptr;

    /*
     Checks if a price is larger than the largest, 2nd largest, or 3rd largest
     if it is, it shits everything down to make room
     */
    for (stock* s : *stocks) {
        float price = s->getPrice();
        if (!largest || price >= largest->getPrice()) { // > largest
            smallest = middle;
            middle = largest;
            largest = s;
        } else if (!middle || price >= middle->getPrice()) { // > middle
            smallest = middle;
            middle = s;
        } else if (!smallest || price >= smallest->getPrice()) { // > smallest
            smallest = s;
        }
    }
}

void fund::calcPrice() {
    setPrice((largest->getPrice() * 0.4f) + (middle->getPrice() * 0.35f) + (smallest->getPrice() * 0.35f));

    // inits price if needed (I couldn't think of a better solotion :/)
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