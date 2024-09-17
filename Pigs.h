#ifndef PIGS_H
#define PIGS_H

#include "Barn.h"

// This class will contains methods relating to the breeding, selling ,etc of pigs.
// This class inherits from the Barn class.
class Pigs : public Barn {
    protected:
    // The attributes of the function are initialised. 
    int maxPigCapacity;
<<<<<<< HEAD
    int currentPigCount;
    double growthRate;
=======
>>>>>>> 2cb4ce6a29de8b333bd32748f60a9b47648ce83e
    int PigCount;
    int PigPrice; 

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
};

#endif