#include "stock.h"

stock::stock(string name, float revenue, float expenditures, float assets, 
             float rangeLower, float rangeUpper, float hype, int numLeft)
    : security(name, (revenue * hype) / numLeft)
{
    this->revenue = revenue;
    this->expenditures = expenditures;
    this->assets = assets;
    this->rangeLower = rangeLower;
    this->rangeUpper = rangeUpper;
    this->hype = hype;
    this->numLeft = numLeft;
    initHistory();
}

void stock::simDay() {
    nextDay();
    applyRange();
    calcPrice();
    trade();
    calcPrice();
    calcHype();
}

void stock::applyRange() {
    // Change profits
    revenue += genRandFloat(rangeLower, rangeUpper);
    expenditures -= genRandFloat(rangeLower, rangeUpper) / 2;

    // Change assets and subtract that from expenditures
    float assetChange = genRandFloat(rangeLower, rangeUpper) / 4;
    assets += assetChange;
    expenditures += assetChange;
}

void stock::calcPrice() {
    setPrice(revenue * hype / numLeft);
}

void stock::trade() {
    numLeft = (revenue * hype) / getPrice();
}

void stock::calcHype() {
    float dayChange = getChange(1);
    float weekChange = getChange(5);
    float monthChange = getChange(20);

    // Handles not enough elapsed time
    if (dayChange == -1.0f) {
        dayChange = 0.0f;
    }
    if (weekChange == -1.0f) {
        weekChange = 0.0f;
    }
    if (monthChange == -1.0f) {
        monthChange = 0.0f;
    }

    hype += (dayChange + weekChange + monthChange) / 3 + genRandFloat(-0.1f, 0.1f);
}

float stock::genRandFloat(float lower, float upper) {
    random_device rng;
    mt19937 gen(rng());
    uniform_int_distribution<float> range(lower, upper);
    return range(gen);
}

string stock::debugString() {
    return ("%s - %s, %s$ - %s, %s, %s | + %s -%s, assets %s, hype %s", 
        getName, getPrice, to_string(getChange(1)), to_string(getChange(5)), to_string(getChange(20)), to_string(getTotalChange()),
    to_string(revenue), to_string(expenditures), to_string(assets), to_string(hype));
}