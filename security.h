#ifndef STOCK_H_EXISTS
#define STOCK_H_EXISTS

#include <array>
#include <iostream>
#include <random>
#include <string>
#include <stdbool.h>

using namespace std;

class security {
private:
    string name;
    float price;
    float initPrice;
    array<float, 20> monthHist;
    int currentDay;

public:
    string getName();
    float getPrice();
    float getChange(int daysAgo);
    void simDay();
    void calcPrice();
    string toString();
};
#endif