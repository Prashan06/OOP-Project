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
        void executeEvent(Farmer farmer, Cows cow, Pigs pig, Barn barn);
};





#endif