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
    float current = getPrice();
    setPrice((revenue * hype / numLeft) + genRandFloat(-(current/200), current/200)); // += 1% for more variation
}

void stock::trade() {
    float demand = (revenue * hype) / getPrice();
    numLeft = std::max(1.0f, numLeft + (demand - numLeft) * 0.1f);
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

    float newHype = dayChange / 100.0f;
    if (newHype > 0) {
        hype += (min(0.005f, newHype) + genRandFloat(-0.01f, 0.01f));
    } else {
        hype += (max(-0.005f, newHype) - genRandFloat(-0.01f, 0.01f));
    }
}

float stock::genRandFloat(float lower, float upper) {
    random_device rng;
    mt19937 gen(rng());
    uniform_real_distribution <float> range(lower, upper);
    return range(gen);
}

string stock::debugString() {
    ostringstream oss;
    oss << fixed << setprecision(2);
    oss << getName() << " - $" << getPrice()
        << " | " << getChange(1)  << "% today"
        << ", " << getChange(5)  << "% week"
        << ", " << getChange(20) << "% month"
        << ", " << getTotalChange() << "% all time"
        << " | rev $" << revenue
        << ", exp $" << expenditures
        << ", assets $" << assets
        << ", hype " << hype;
    return oss.str();
}