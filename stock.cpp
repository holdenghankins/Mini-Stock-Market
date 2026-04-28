#include "stock.h"

stock::stock(string name, float revenue, float expenditures, float netAssets, float hype, int numLeft)
    : security(name, (revenue * hype) / numLeft)
{
    this->revenue = revenue;
    this->expenditures = expenditures;
    this->netAssets = netAssets;
    this->hype = hype;
    this->numLeft = numLeft;

    // Load default values for unititiated variables
    this->rangeLower = 0;
    this->rangeUpper = 0;
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
    expenditures -= genRandFloat(rangeLower, rangeUpper) / 2.0f;

    // Change assets and subtract that from expenditures
    float assetChange = genRandFloat(rangeLower, rangeUpper) / 4.0f;
    netAssets += assetChange;
    if (assetChange < 0.0f) {
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

    // Handles not enough elapsed time
    if (dayChange == -1.0f) {
        dayChange = 0.0f;
    }

    // Keeps increment small and localized sim doesn't speed off
    float newHype = dayChange / 100;

    /*
    Adds some variability to the movement
    else if used to check min/max and make sure hype doesn't get too big
     */
    if (newHype > 0.0f) {
        hype += (min(0.005f, newHype) + genRandFloat(-0.01f, 0.01f));
    } else {
        hype += (max(-0.005f, newHype) - genRandFloat(-0.01f, 0.01f));
    }

    // Pops bubbles
    if (genRandFloat(hype, 1000.0f) > 999.0f) {
        hype = 0.8f;
    }
}

void stock::adjustRange() {
    // Finds most fitting value for company's model
    rangeUpper = max(((revenue - expenditures) / 1000.0f), ((netAssets - expenditures) / 1000.0f));
    rangeUpper = max(rangeUpper, revenue / 100000.0f);

    // Finds fitting min
    rangeLower = min(((netAssets - expenditures) / 1000.0f), ((revenue - expenditures) / 1000.0f));
    rangeLower = min(rangeLower, -expenditures / 100000.0f);
}

float stock::genRandFloat(float lower, float upper) {
    // I am also not very fond of this
    random_device rng;
    mt19937 gen(rng());
    uniform_real_distribution <float> range(lower, upper);
    return range(gen);
}

void stock::applyInterest() {
    int interest = netAssets * 0.005f;

    // Interest means assets slowly affect bottom line
    if (interest > 0) {
        revenue += interest;
    } else {
        expenditures += interest;
    }
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