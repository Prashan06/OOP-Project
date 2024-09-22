#ifndef PIGS_H
#define PIGS_H

#include "Barn.h"
#include "ctime"

// This class will contains methods relating to the breeding, selling ,etc of pigs.
// This class inherits from the Barn class.
class Pigs : public Barn {
    protected:
    // The attributes of the function are initialised. 
        int maxPigCapacity;
        int pigGrowthRate;
        int pigCount;
        int pigPrice; 
        int boughtPigs;
        int numberOfTimesPigsAreBought;  
        int* pigArray = new int [numberOfTimesPigsAreBought];
        int* timeArray = new int [numberOfTimesPigsAreBought];
        int increaseCapacityPrice;
        int sellReadyPigCount;
        int sellReadyPigPrice;
        int sellPrice;
        int newMoney;

    public:
        Pigs();
        int setMaxAnimalCapacity(int maxPigCapacity);
        void increaseBarnCapacity();
        int getPigCount();
        void sellItem(); 
        void buyItem();
        int getNumberOfTimesPigsAreBought();
        int* getPigArray();
        int* getTimeArray();
        void setPigCount(int pigCount);
        void setNumberOfTimesPigsAreBought(int numberOfTimesPigsAreBought); 
        ~Pigs();
};

#endif