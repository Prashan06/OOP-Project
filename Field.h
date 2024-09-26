#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include "Farm.h"
#include "Farmer.h"
#include <ctime>

class Field : public Farm, public Farmer {
    protected:
    int wheatCount;
    int cornCount;
    int wheatGrowthRate;
    int cornGrowthRate;
    int cropCount;
    int dayCount;
    int fertiliserDuration;
    time_t fertiliserTimer;
    time_t PesticideTimer;


    public:
    Field();
    void Fertilisation();
    void Pesticide();
    int getCropCount();
    void setCropCount(int wheatCount, int cornCount);    
    virtual void increaseMaxFieldCapacity();
    virtual void setMaxFieldCapacity();
};

#endif