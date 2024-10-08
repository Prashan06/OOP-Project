#ifndef COW_H
#define COW_H

#include "Barn.h"
#include "Events.h"
#include "Farmer.h"

#include <ctime>
#include <chrono>
#include <iostream>

using namespace std;



class Cow: public Barn, public Events{

    protected:

    public:
    Cow();
    ~Cow();
    void applyHighYield(Farmer* farmer);
    void Event(Farmer &farmer);
};

#endif