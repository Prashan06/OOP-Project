#ifndef WHEAT_H
#define WHEAT_H

#include "Field.h"
#include "ctime"

// This class will contains methods relating to the breeding, selling ,etc of pigs.
// This class inherits from the Barn class.
class Wheat : public Field {
    protected:
    // The attributes of the function are initialised. 
        int maxWheatCapacity;
        int wheatGrowthRate;
        int wheatCount;
        int wheatPrice; 
        int boughtWheat;
        int numberOfTimesWheatAreBought;  
        int* wheatArray = new int [numberOfTimesWheatAreBought];
        int* timeArray = new int [numberOfTimesWheatAreBought];
        int increaseCapacityPrice;
        int sellReadyWheatCount;
        int sellReadyWheatPrice;
        int sellPrice;
        int newMoney;

    public:
        Wheat();
        int setMaxCropsCapacity(int maxWheatCapacity);
        int getWheatCount();
        void increaseFieldCapacity();
        int getPigCount();
        void sellItem();
        int getNumberOfItems(); 
        void buyItem();
        void Fertilsation();
        ~Wheat();
};

#endif
