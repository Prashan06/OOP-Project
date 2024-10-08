#ifndef PIG_H
#define PIG_H

#include <ctime>
#include <chrono>
#include <iostream>
#include "Barn.h"
#include "Events.h"

using namespace std;

class Pig: public Barn, public Events {

    protected:
    
    public:
    Pig();
    ~Pig();
    void applyHighYield(int &money, int &pigCount, Pig** pig);
    void Event(int &pigCount, Pig** pig);
    Pig* createNewPig();
};

#endif