#ifndef WHEAT_H
#define WHEAT_H

#include "Field.h"
#include "Events.h"
#include "Corn.h"
#include "Cow.h"
#include "Pig.h"

class Wheat: public Field, public Events {

    protected:
         bool wheatEvent = false;
    public:
        Wheat();
        ~Wheat();
        void Event(int* count);
        void applyHighYield(int *money);
        void setWheatEvent(bool wheatEvent);
        bool getWheatEvent();

};

#endif