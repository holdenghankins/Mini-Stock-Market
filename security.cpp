#include "security.h"


security::security() {
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

void security::setInitPrice(float p) {
    initPrice = p;
}

void security::initHistory() {
    currentDay = 0;
    for (int i = 0; i < 20; i++) monthHist.at(i) = -1.0f;
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
    while (dayToGet < 0) {
        dayToGet += 20;
    }
    if (monthHist.at(dayToGet) < 0) {
        return 0.0f;
    }
    return calcPercentChange(price, monthHist.at(dayToGet));
}

float security::getTotalChange() {
    return calcPercentChange(price, initPrice);
}

void security::nextDay() {
    currentDay = (currentDay + 1) % 20;
    monthHist.at(currentDay) = price;
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