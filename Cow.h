#ifndef COW_H
#define COW_H

#include "Barn.h"
#include "Events.h"

#include <ctime>
#include <chrono>

class Cow: public Barn, public Events{

    protected:

    public:
    Cow();
    ~Cow();
    void applyHighYield();
    void Event();
};

#endif