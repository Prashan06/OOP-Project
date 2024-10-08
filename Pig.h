#ifndef PIG_H
#define PIG_H

#include <ctime>
#include <chrono>
#include <iostream>
#include "Barn.h"
#include "Events.h"
#include "Wheat.h"
#include "Corn.h"
#include "Cow.h"

using namespace std;

class Pig: public Barn, public Events {

    protected:
    
    public:
    Pig();
    ~Pig();
    void applyHighYield(int &money, int &pigCount, Pig** pig);
    void Event(int &count, Cow** cow, Pig** pig, Corn** corn, Wheat** wheat);
    Pig* createNewPig();
};

#endif