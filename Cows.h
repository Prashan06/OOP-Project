#ifndef COWS_H
#define COWS_H

#include "Barn.h"
#include "ctime"

// This class will contains methods relating to the breeding, selling ,etc of pigs.
// This class inherits from the Barn class.
class Cows : public Barn {
    protected:
    // The attributes of the function are initialised. 
        int maxCowCapacity;
        int cowGrowthRate;
        int cowCount;
        int cowPrice; 
        int boughtCows;
        int numberOfTimesCowsAreBought;  
        int* cowArray = new int [numberOfTimesCowsAreBought];
        int* timeArray = new int [numberOfTimesCowsAreBought];
        int increaseCapacityPrice;
        int sellReadyCowCount;
        int sellReadyCowPrice;
        int sellPrice;
        int newMoney;
    

    public:
        Cows();
        int setMaxAnimalCapacity(int maxCowCapacity);
        void increaseBarnCapacity();
        int getCowCount();
        void sellItem();
        void buyItem();
        ~Cows();
};

#endif