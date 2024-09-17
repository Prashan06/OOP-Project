#ifndef BARN_H
#define BARN_H

#include <iostream>
#include "Farm.h"
#include "Farmer.h"

using namespace std;

class Barn : public Farm, public Farmer {
    protected:
        int animalCount;
        int breedPrice;
    public:
        Barn();
        void breedAnimals();
        int getAnimalCount();
        void setAnimalCount(int pigCount, int cowCount, int sheepCount);
        virtual int setMaxAnimalCapacity();
        virtual int MaxBarnCapacity();
        virtual void increaseBarnCapacity();
        void setPrice();
        int getPrice();
};



#endif