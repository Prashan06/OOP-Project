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
        bool pigEvent;
    public:
        Pig();
        void applyHighYield(int *money);
        void Event(int* count);
        Pig* createNewPig();
        void setPigEvent(bool pigEvent);
        bool getPigEvent();
};

#endif