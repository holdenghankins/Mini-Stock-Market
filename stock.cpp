#include "stock.h"

stock::stock(string name, float revenue, float expenditures, float netAssets, float hype, int numLeft)
    : security(name, (revenue * hype) / numLeft)
{
    this->revenue = revenue;
    this->expenditures = expenditures;
    this->netAssets = netAssets;
    this->rangeLower = 0;
    this->rangeUpper = 0;
    this->hype = hype;
    this->numLeft = numLeft;
    initHistory();
}

void stock::simDay() {
    // Price at open
    calcPrice();

    // Market moves to match price
    trade();
    calcPrice();

    // People react to changes after market close
    calcHype();

    // Buisness expands or shrinks
    adjustRange();
    applyRange();

    // Investments and debt grow
    applyInterest();

    // Move forward 1 day
    nextDay();
}

void stock::applyRange() {
    // Change profits
    revenue += genRandFloat(rangeLower, rangeUpper);
    expenditures -= genRandFloat(rangeLower, rangeUpper) / 2;

    // Change assets and subtract that from expenditures
    float assetChange = genRandFloat(rangeLower, rangeUpper) / 4;
    netAssets += assetChange;
    if (assetChange < 0) {
        revenue += assetChange;
    }
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

    // Pops bubbles
    if (genRandFloat(hype, 1000) > 999) {
        hype = 1;
    }
}

void stock::adjustRange() {
    rangeUpper = max(((revenue - expenditures) / 1000), ((netAssets - expenditures) / 1000));
    rangeUpper = max(rangeUpper, revenue / 100000);

    rangeLower = min(((netAssets - expenditures) / 1000), ((revenue - expenditures) / 1000));
    rangeLower = min(rangeLower, -expenditures / 100000);
}

float stock::genRandFloat(float lower, float upper) {
    random_device rng;
    mt19937 gen(rng());
    uniform_real_distribution <float> range(lower, upper);
    return range(gen);
}

void stock::applyInterest() {
    netAssets *= 0.005;
}

string stock::debugString() {
    ostringstream oss;
    oss << fixed << setprecision(2);
    oss << getName() << " - $" << getPrice()
        << " | " << getChange(1)  << "% today"<< ", " << getChange(5)  << "% week"
        << ", " << getChange(20) << "% month" << ", " << getTotalChange() 
        << "% all time" << " | rev $" << revenue << ", exp $" << expenditures
        << ", assets $" << netAssets << ", hype " << hype
        << "| " << rangeLower << " -> " << rangeUpper;
    return oss.str();
}