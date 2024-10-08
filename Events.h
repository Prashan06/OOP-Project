#ifndef EVENTS_H
#define EVENTS_H

#include "Wheat.h"
#include "Corn.h"
#include "Pig.h"
#include "Cow.h"

class Events {
    public:
    virtual void Event(int* count) = 0;
};

#endif