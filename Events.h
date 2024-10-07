#ifndef EVENTS_H
#define EVENTS_H

#include "Farmer.h"

class Events {
    public:
    virtual void Event(Farmer farmer) = 0;
};

#endif