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
    int DayCount;
    time_t time;
    std::string FarmName;

    public:
    Farmer();
    float getMoneyCount();
    void setMoneyCount();
    // void addFields();
    // void addBarns();
    // void addTools();
    void getStatus();
    void setFarmName();
    std::string getFarmName();
    int getDayCount();
};

#endif
