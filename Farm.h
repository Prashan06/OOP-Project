#ifndef FARM_H
#define FARM_H

#include <iostream>

class Farm {

    public:
        virtual int sellItem() = 0;
        virtual double setGrowthRate() = 0;
        virtual void setPrice() = 0;
        virtual int getPrice() = 0;
        virtual int getNumberOfItems() = 0; 
        virtual void buyItem() = 0;
};

#endif