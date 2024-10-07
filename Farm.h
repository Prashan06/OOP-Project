#ifndef FARM_H
#define FARM_H

#include <chrono>
#include "Farmer.h"
#include "Events.h"

class Farm {

    protected:
        
        int buyPrice;
        int sellPrice;
        int sellTime;
        time_t timer;
        string optionChoice;

    public:
        Farm();
        virtual void applySpeedGrowth(Farmer ourFarmer);
        virtual void applyHighYield(Farmer ourFarmer);
        int setBuyPrice(int buyPrice);
        int getBuyPrice();
        void setSellPrice(int sellPrice);
        int getSellPrice();
        void setSellTime(int sellTime);
        int getSellTime();
        int getTimer();
        ~Farm();

};

#endif
