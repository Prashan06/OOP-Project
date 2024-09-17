#ifndef PIGS_H
#define PIGS_H

#include "Barn.h"

// This class will contains methods relating to the breeding, selling ,etc of pigs.
// This class inherits from the Barn class.
class Pigs : public Barn {
    protected:
    int maxPigCapacity;
    int currentPigCount;
    double growthRate;

    public:
    Pigs();
    int setMaxAnimalCapacity();
    int MaxBarnCapacity();
    void increaseBarnCapacity();
    void setPrice();
    int sellItem();
    double setGrowthRate();
    void setPrice();
    int getPrice();
    int getNumberOfItems(); 
    void BuyPig();
};

#endif