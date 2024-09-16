#ifndef BARN_H
#define BARN_H

#include <iostream>
#include "Farm.h"

using namespace std;

class Barn : public Farm {
    protected:
        int animalCount;
        int breedPrice;
    public:
        Barn();
        void breedAnimals();
        int getAnimalCount();
        virtual int setMaxAnimalCapacity();
        virtual int MaxBarnCapacity();
        virtual void increaseBarnCapacity();
        void setPrice();
};


#endif