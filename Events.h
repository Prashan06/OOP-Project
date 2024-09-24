#ifndef EVENTS.H
#define EVENTS.H
#include <iostream>
#include "Farmer.h"
#include "Pigs.h"
#include "Cows.h"
#include "Corn.h"
#include "Wheat.h"
#include "SprayingMachine.h"
#include "FertilizingMachine.h"

using namespace std;

class Events : public Farmer , public Pigs, public Cows, public Wheat, public Corn, public SprayingMachine, public FertilizingMachine{
    protected:
    public:
        void executeEvent(Farmer farmer, Cows cow, Pigs pig, Barn barn, SprayingMachine sMachine, FerilizingMachine fMachine);
};





#endif