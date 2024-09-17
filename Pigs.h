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
    int currentPigCount;
    double growthRate;
    int PigCount;
    int PigPrice; 
    int boughtPigs;
    int numberOfTimesPigsAreBought;   
    int* pigArray = new int [numberOfTimesPigsAreBought];
    int* timeArray = new int [numberOfTimesPigsAreBought];

    int PigPrice;
    bool sellReady;
    int sellReadyPigCount;
    int sellPrice;
    

    public:
    Pigs();
    int getAnimalCount();
    int setMaxAnimalCapacity(int maxPigCapacity);
    void increaseBarnCapacity();
    int getPigCount();
    int sellItem();
    double setGrowthRate();
    void setPrice();
    int getPrice();
    int getNumberOfItems(); 
    void buyPig();
};

#endif