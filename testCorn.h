#ifndef CORN_H
#define CORN_H

#include "Field.h"
#include "ctime"

// This class will contains methods relating to the growing, selling, etc of corn.
// This class inherits from the Field class.

class Corn : public Field {

    protected:
    
        int maxCornCapacity;
        int cornGrowthRate;
        int cornCount;
        int cornPrice; 
        int boughtCorn;
        int numberOfTimesCornIsBought;  
        int* cornArray = new int [numberOfTimesCornIsBought];
        int* timeArray = new int [numberOfTimesCornIsBought];
        int increaseCapacityPrice;
        int sellReadyCornCount;
        int sellReadyCornPrice;
        int sellPrice;
        int newMoney; 
    

    public:
    
        Corn();
        void setMaxCropCapacity(int maxCornCapacity);
        void increaseFieldCapacity();
        int getCornCount();
        void sellItem();
        void buyItem();
        int getNumberOfTimesCornIsBought();
        void setNumberOfTimesCornIsBought(int numberOfTimesCornIsBought);
        int* getTimeArray();
        int* getCornArray();
        void setCornCount(int cornCount);
        ~Corn();
};

#endif