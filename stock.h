#ifndef STOCK_H_EXISTS
#define STOCK_H_EXISTS

#include <random>
#include "security.h"

using namespace std;

class stock : public security {
private:
    // Attributes
    float revenue;
    float expenditures;
    float netAssets;
    float rangeLower;
    float rangeUpper;
    float hype;
    float history[30];
    int numLeft;

    // PRIVATE METHODS

    // Modifies the values of revenue, expenditures, and assets using the upper and lower range values
    void applyRange();

    // Sets price to (revenue * hype) / numLeft
    void calcPrice();

    // Sets numLeft to match price using (revenue * hype) / price
    void trade();

    // Adds 1 day, 1 week, and 1 month change, / 3
    void calcHype();

    // Adds assets and expendatures together, then adds to either upper or lower bound
    void adjustRange();
    float genRandFloat(float lower, float upper);
    void applyInterest();
public:
    stock(string name, float revenue, float expenditures, float netAssets, float rangeLower, float rangeUpper, 
        float hype, int numLeft);
    void simDay();
    string debugString();
};
#endif