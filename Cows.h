#ifndef COWS_H
#define COWS_H

#include "Barn.h"

// This class will contains methods relating to the breeding, selling ,etc of Cows.
// This class inherits from the Barn class.
class Cows : public Barn {
    protected:

    public:
    Cows();
    int getAnimalCount();
    int setMaxAnimalCapacity();
    int MaxBarnCapacity();
    void increaseBarnCapacity();
    void setPrice();
    int sellItem() = 0;
    double setGrowthRate() = 0;
    void setPrice() = 0;
    int getPrice() = 0;
    int getNumberOfItems() = 0; 
};

#endif