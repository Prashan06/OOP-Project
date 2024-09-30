#ifndef FIELD_H
#define FIELD_H

#include "Farm.h"

class Field{

    protected:

    int cropPrice; // modified in wheat and corn classes

    int cropGrowth; // tracks current stage of growth

    int fertilizerPrice; 
    int PesticidePrice;     

    float fertilizerPercentage; // tracks how much fertilizer the field has received, is a percentage
    float pesticidePercentage; // tracks how much pesticide the field has received, is a percentage

     virtual int maxFieldCapacity();

    public:

    virtual void Fertilzation(); // Increases fertilizationPercentage must not exceed 100%
    virtual void Pesticide(); // Increases pesticidePercentage must not exceed 100%

    // set & get functions

    void setCropPrice();
    int getCropPrice();

    void setCropGrowth();
    int getCropGrowth();

    void setFertilizerPrice();
    int getFertilizerPrice();

    void setPesticidePrice();
    int getPesticidePrice();

    void setFertilizerPercentage();
    float getFertilizerPercentage();

    void setFertilizerPercentage();
    float getFertilizerPercentage();

    virtual int increaseMaxFieldCapacity();
    virtual int getMaxFieldCapacity();
    
    virtual int currentYield(); // Uses fertilizationPercentage, pesticidePercentage, growthLevel to calculate currentYield

};

#endif