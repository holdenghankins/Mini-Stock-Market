#include <array>
#include <iostream>
#include <random>
#include <string>
#include "security.h"

using namespace std;

security::security(string name, float initPrice) {
    this->name = name;
    this->initPrice = initPrice;
    price = initPrice;
    currentDay = 0;
    monthHist.at(0) = price;
    for (int i = 1; i < 21; i++) {
        monthHist.at(i) = -1;
    }
}

string security::getName() {
    return name;
}

float security::getPrice() {
    return price;
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

float security::calcPercentChange(float f1, float f2) {
    return ((f1 - f2) / f2) * 100;
}

string security::toString() {
    return ("%s: %f | %f today, %f week, %f month, %f all time", 
        name, price, to_string(getChange(1)), to_string(getChange(5)), to_string(getChange(20)), to_string(getTotalChange()));
}