#ifndef PIG_H
#define PIG_H

#include "Barn.h"
#include "Events.h"
#include "Farmer.h"

#include <ctime>
#include <chrono>
#include <iostream>

using namespace std;

class Pig: public Barn, public Events {

    protected:
    
    public:
    Pig();
    ~Pig();
    void applyHighYield(Farmer ourFarmer);
    void Event(Farmer farmer);
    Pig* createNewPig();
};

#endif