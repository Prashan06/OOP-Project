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
    virtual int setMaxAnimalCapacity();
    virtual int MaxBarnCapacity();
    virtual void increaseBarnCapacity();
    void setPrice();
    virtual int sellItem() = 0;
    virtual double setGrowthRate() = 0;
    virtual void setPrice() = 0;
    virtual int getPrice() = 0;
    virtual void getNumberOfItems() = 0; 
};

#endif