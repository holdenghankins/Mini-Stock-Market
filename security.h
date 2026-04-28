#ifndef SECURITY_H_EXISTS
#define SECURITY_H_EXISTS

#include <array>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class security {
private:
    string name;

    // valuation / num left
    float price;

    // day 1 price
    float initPrice;

    // Cyclic array representing which day in the month we are
    // Used for checking changes in price history
    array<float, 20> monthHist;
    int currentDay;

    // Internal function for getChange and getTotalChange
    float calcPercentChange(float, float);

public:
    security();
    security(string name, float initPrice); // price set to initPrice upon creation
    string getName();

    // Used by extending classes to make changes to prices during simulating
    float getPrice();
    void setPrice(float price);

    // Moves day forward in the cyclic array
    void nextDay();

    // Used speficially by fund which lacks a price upon creation
    void setInitPrice(float price);

    // Initilizes the history array with -1 values while setting day[0] to price
    // Sets the day to 0
    void initHistory();

    // Give the change as a percentage
    float getChange(int daysAgo);

    // Change between now and init
    float getTotalChange();

    // Method that runs each stock's "turn", which is used to represent a single day of trading on the market
    virtual void simDay() = 0;

    // Applies all internal variables to generate a price for a single day
    virtual void calcPrice() = 0;

    // name: price | day change, week, month, all time
    string toString();
};
#endif