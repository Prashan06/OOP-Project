#ifndef CORN_H
#define CORN_H

#include "Field.h"
#include "ctime"

// This class will contains methods relating to the breeding, selling ,etc of pigs.
// This class inherits from the Barn class.
class Corn : public Field {
    protected:
    // The attributes of the function are initialised. 
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
        int setMaxCropCapacity(int maxCornCapacity);
        void increaseFieldCapacity();
        int getCornCount();
        void sellItem();
        void buyItem();
        ~Corn();
};

#endif