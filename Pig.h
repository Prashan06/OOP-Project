#ifndef Pig_H
#define Pig_H

#include <iostream>
#include "Barn.h"

using namespace std;

// this class is going to contain methods for buying and selling pigs 
// so that the user can make money on the farm

class Pig : public Barn {
    protected:
        int pigcount;
        double growthRate;
    public:
        int setMaxAnimalCapacity();
        int MaxBarnCapacity();
        void increaseBarnCapacity();
        int sellItem();
        double setGrowthRate();
        int getPigCount();
        void setPigCount();


};


#endif