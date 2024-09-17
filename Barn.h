#ifndef BARN_H
#define BARN_H

#include <iostream>
#include "Farm.h"
#include "Farmer.h"

using namespace std;

class Barn : public Farm, public Farmer {
    protected:
        int animalCount;
    public:
        Barn();
        int getAnimalCount();
        void setAnimalCount(int pigCount, int cowCount);
        virtual int setMaxAnimalCapacity();
        virtual int MaxBarnCapacity();
        virtual void increaseBarnCapacity();
};



#endif