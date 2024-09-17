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
    int PigPrice; 
    int boughtPigs;
<<<<<<< HEAD
    int numberOfTimesPigsAreBought;   
    int* pigArray = new int [numberOfTimesPigsAreBought];

=======
    int numberOfTimesPigsAreBought;
    int* pigArray = new int[numberOfTimesPigsAreBought];
>>>>>>> 92d0cd3fed12fdd6e85a0969b7c3178d44f2a011
    int PigPrice;
    bool sellReady;
    int sellReadyPigCount;
    int sellPrice;
<<<<<<< HEAD
    
=======

>>>>>>> 92d0cd3fed12fdd6e85a0969b7c3178d44f2a011
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