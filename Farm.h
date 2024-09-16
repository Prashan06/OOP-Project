#ifndef FARM_H
#define FARM_H

#include <iostream>

class Farm {

    public:
        virtual int sellItem() = 0;
        virtual double setGrowthRate() = 0;
        virtual void setPrice() = 0;
        virtual void getPrice() = 0;
        virtual void getNumberOfItems() = 0; 
};

#endif