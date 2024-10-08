#ifndef PIG_H
#define PIG_H

#include <ctime>
#include <chrono>
#include <iostream>
#include "Barn.h"
#include "Events.h"
#include "Farmer.h"

using namespace std;

class Pig: public Barn, public Events {

    protected:
    
    public:
    Pig();
    ~Pig();
    void applyHighYield(Farmer &farmer);
    void Event(Farmer &farmer);
    Pig* createNewPig();
};

#endif