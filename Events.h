#ifndef EVENTS_H
#define EVENTS_H

#include "Farmer.h"

class Events {
    public:
    virtual void Event(Farmer ourfarmer) = 0;
};

#endif