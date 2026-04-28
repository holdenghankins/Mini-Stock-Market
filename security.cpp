#include "security.h"

security::security() { // default
    this->name = "";
    this->initPrice = this->price = 0.0f;
    initHistory();
}

security::security(string name, float initPrice) {
    this->name = name;
    this->initPrice = initPrice;
    price = initPrice;
    initHistory();
}

void security::setInitPrice(float price) {
    initPrice = price;
}

void security::initHistory() {
    currentDay = 0;
    for (int i = 0; i < 20; i++) monthHist.at(i) = -1.0f; // -1 just good for catching empty values
}

string security::getName() {
    return name;
}

float security::getPrice() {
    return price;
}

void security::setPrice(float price) {
    this->price = max(price, 0.00f); // prevents negative prices
}

float security::getChange(int daysAgo) {
    int dayToGet = currentDay - daysAgo;
    // "Travese" cyclic array
    while (dayToGet < 0) {
        dayToGet += 20;
    }

    // Detect if value was empty
    if (monthHist.at(dayToGet) < 0) {
        return 0.0f;
    }
    return calcPercentChange(price, monthHist.at(dayToGet));
}

float security::getTotalChange() { // This only exists for readability
    return calcPercentChange(price, initPrice);
}

void security::nextDay() {
    currentDay = (currentDay + 1) % 20; // Keeps num in array
    monthHist.at(currentDay) = price; // Saves price
}

float security::calcPercentChange(float f1, float f2) {
    return ((f1 - f2) / f2) * 100;
}

string security::toString() {
    ostringstream oss;
    oss << fixed << setprecision(2);
    oss << name << ": $" << price
        << " | " << getChange(1)  << "% today" << ", " << getChange(5)  << "% week"
        << ", " << getChange(20) << "% month" << ", " << getTotalChange() << "% all time";
    return oss.str();
}