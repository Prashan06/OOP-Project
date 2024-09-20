#ifndef EVENTS.H
#define EVENTS.H
#include <iostream>
#include "Farmer.h"
#include "Pigs.h"
#include "Cows.h"
#include "Corn.h"
#include "Wheat.h"

using namespace std;

class Events : public Farmer , public Pigs, public Cows, public Wheat, public Corn {
    protected:

    public:
        void pestInvasion();
        void animalDisease();
        void Tax();

};





#endif