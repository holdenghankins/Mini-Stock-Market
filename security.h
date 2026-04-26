#ifndef STOCK_H_EXISTS
#define STOCK_H_EXISTS

#include <array>
#include <iostream>
#include <random>
#include <string>

using namespace std;

class security {
private:
    string name;
    float price;
    float initPrice;
    array<float, 20> monthHist;
    int currentDay;

    // Internal function for getChange and getTotalChange
    float calcPercentChange(float, float);

public:
    security(string name, float initPrice);
    string getName();
    float getPrice();

    // Give the change as a percentage
    float getChange(int daysAgo);
    float getTotalChange();

    // Method that runs each stock's "turn", which is used to represent a single day of trading on the market
    virtual void simDay() = 0;

    // Applies all internal variables to generate a price for a single day
    virtual void calcPrice() = 0;

    // name: price | day change, week, month, all time
    string toString();
};
#endif