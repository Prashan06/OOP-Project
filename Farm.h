#ifndef FARM_H
#define FARM_H

#include <iostream>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;


class Farm {

    protected:
        
        int buyPrice;
        int sellPrice;
        int sellTime;
        time_t timer;
        string optionChoice;
        bool highYieldBought;
        bool speedGrowth;

    public:
        Farm();

        virtual void applySpeedGrowth(Farmer &farmer);
        virtual void applyHighYield(Farmer &ourFarmer);
        void setBuyPrice(int buyPrice);
        int getBuyPrice();
        void setSellPrice(int sellPrice);
        int getSellPrice();
        void setSellTime(int sellTime);
        int getSellTime();
        int getTimer();
        ~Farm();

};

#endif
