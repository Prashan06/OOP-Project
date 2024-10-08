#ifndef FARM_H
#define FARM_H

#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include "Farmer.h"
#include "Events.h"

using namespace std;


class Farm {

    protected:
        
        int buyPrice;
        int sellPrice;
        int sellTime;
        time_t timer;
        string optionChoice;
        int cowCount;
        int pigCount;
        int wheatCount;
        int cornCount;

    public:
        Farm();
        int getCowCount();
        int getPigCount();
        int getWheatCount();
        int getCornCount();
        void setCowCount(int cowCount);
        void setPigCount(int pigCount);
        void setWheatCount(int wheatCount);
        void setCornCount(int cornCount);
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
