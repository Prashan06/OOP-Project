#ifndef FARMER_H
#define FARMER_H

#include <iostream>
#include <string>

class Farmer {
    protected:
    float Money;
    // Field** Fields;
	// Barn** Barns;
	// Tool** Tools;

    int DayLength;
    int DayCount;
    int time;
    std::string FarmName;

    public:
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