#ifndef FARM_H
#define FARM_H

#include <iostream>
#include <ctime>
#include <chrono>
#include <string>

#include "Events.h"

using namespace std;

// This class contains functions and attributes that manage the whole farm. 
// This class has functions that are inherited by Barn and Field. As Cow,Pig inherit from Barn and 
// as Wheat and Corn inherit from Field, Cow,Pig,Wheat,and Corn inherit from Farm in three level inheritance.
class Farm {

    protected:
        
        int buyPrice;
        int sellPrice;
        int sellTime;
        time_t timer;
        string optionChoice;
        bool barnSpeedGrowthApplied = false;
        bool fieldSpeedGrowthApplied = false;
        bool pigHighYieldApplied = false;
        bool cowHighYieldApplied = false;
        bool cornHighYieldApplied = false;
        bool wheatHighYieldApplied = false;

    public:
        Farm();
        virtual void applySpeedGrowth(int* money);
        virtual void applyHighYield(int* money);
        void setBuyPrice(int buyPrice);
        int getBuyPrice();
        void setSellPrice(int sellPrice);
        int getSellPrice();
        void setSellTime(int sellTime);
        int getSellTime();
        int getTimer();
        bool getBarnSpeedGrowthApplied();
        bool getFieldSpeedGrowthApplied();
        void setBarnSpeedGrowthApplied(bool barnSpeedGrowthApplied);
        void setFieldSpeedGrowthApplied(bool fieldSpeedGrowthApplied);
        bool getPigHighYieldApplied();
        bool getCowHighYieldApplied();
        bool getWheatHighYieldApplied();
        bool getCornHighYieldApplied();

        void setPigHighYieldApplied(bool pigHighYieldApplied);
        void setCowHighYieldApplied(bool cowHighYieldApplied);
        void setWheatHighYieldApplied(bool wheatHighYieldApplied);
        void setCornHighYieldApplied(bool cornHighYieldApplied);
        bool isReadyToSell ();
};

#endif
