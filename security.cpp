#include "security.h"


security::security() {
    this->name = "";
    this->initPrice, price = 0.0f;
    initHistory();
}

security::security(string name, float initPrice) {
    this->name = name;
    this->initPrice = initPrice;
    price = initPrice;
}

void security::initHistory() {
    currentDay = 0;
    monthHist.at(0) = price;
    for (int i = 1; i < 21; i++) monthHist.at(i) = -1;
}

string security::getName() {
    return name;
}

float security::getPrice() {
    return price;
}

void security::setPrice(float price) {
    this->price = price;
}

float security::getChange(int daysAgo) {
    int dayToGet = currentDay - daysAgo;
    while (currentDay < 0) {
        currentDay += 21;
    }
    return calcPercentChange(price, monthHist.at(daysAgo));
}

float security::getTotalChange() {
    return calcPercentChange(price, initPrice);
}



void security::nextDay() {
    currentDay++;
}

float security::calcPercentChange(float f1, float f2) {
    return ((f1 - f2) / f2) * 100;
}

string security::toString() {
    return ("%s: %s | %s today, %s week, %s month, %s all time", 
        name, price, to_string(getChange(1)), to_string(getChange(5)), to_string(getChange(20)), to_string(getTotalChange()));
}