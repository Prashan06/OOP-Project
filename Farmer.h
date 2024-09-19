#ifndef FARMER_H
#define FARMER_H

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

class Farmer {
    protected:
    int Money;
    // Field** Fields;
    // Barn** Barns;
    // Tool** Tools;

    int DayLength;
    int DayCount = 0;
    time_t time;
    char FarmName[21];
    std::string optionChoice;

    public:
    Farmer();
    int getMoneyCount();
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