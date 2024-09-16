#ifndef FARMER_H
#define FARMER_H

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

class Farmer {
    protected:
    float Money;
    // Field** Fields;
    // Barn** Barns;
    // Tool** Tools;

    int DayLength;
    int DayCount = 0;
    time_t time;
    char FarmName[21];

    public:
    Farmer();
    float getMoneyCount();
    void setMoneyCount(int Money);
    // void addFields();
    // void addBarns();
    // void addTools();
    void getStatus();
    void setFarmName();
    std::string getFarmName();
    int getDayCount();
};

#endif