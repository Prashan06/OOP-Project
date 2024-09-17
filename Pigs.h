#ifndef PIGS_H
#define PIGS_H

#include "Barn.h"

// This class will contains methods relating to the breeding, selling ,etc of pigs.
// This class inherits from the Barn class.
class Pigs : public Barn {
    protected:
    // The attributes of the function are initialised. 
    int maxPigCapacity;
    int currentPigCount;
    double growthRate;
    int PigCount;
<<<<<<< HEAD
    int PigPrice; 
    int boughtPigs;
    int numberOfTimesPigsAreBought = 0;
    int pigArray[numberOfTimesPigsAreBought];

=======
    int PigPrice;
    bool sellReady;
    int sellReadyPigCount;
    int sellPrice;
    
>>>>>>> 96c5cfce2f316782d0ffa3a328f16f7c99d0f47d
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