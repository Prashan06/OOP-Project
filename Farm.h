#ifndef FARM_H
#define FARM_H

#include <chrono>
#include <string>

class Farm {

    protected:
        
        int buyPrice;
        int sellPrice;
        int sellTime;
        time_t timer;
        std::string optionChoice;

    public:
        Farm();
        virtual void applySpeedGrow();
        virtual void applyHighYield();
        int setBuyPrice(int buyPrice);
        int getBuyPrice();
        void setSellPrice(int sellPrice);
        int getSellPrice();
        void setSellTime(int sellTime);
        int getSellTime();
        ~Farm();

};

#endif