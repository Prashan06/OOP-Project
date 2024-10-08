#ifndef COW_H
#define COW_H

#include "Barn.h"
#include "Events.h"
#include "Wheat.h"
#include "Corn.h"
#include "Pig.h"

#include <ctime>
#include <chrono>
#include <iostream>

using namespace std;



class Cow: public Barn, public Events{

    protected:
        bool cowEvent;
    public:
    Cow();
    void applyHighYield(int* money);
    void Event(int* count);
    void setCowEvent(bool cowEvent);
    bool getCowEvent();
};

#endif