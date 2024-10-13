#ifndef WHEAT_H
#define WHEAT_H

#include "Field.h"
#include "Events.h"

// This class has functions and attributes that manage the wheat in the farm. This class inherits from Field and events
class Wheat: public Field, public Events{

    protected:

        bool wheatEvent; 

    public:

        Wheat(); //constructor
        void Event(int* count);
        void applyHighYield(int *money); //modifies sellPrice & money(from farmer)

        //getter & setter for wheatEvent
        void setWheatEvent(bool wheatEvent);
        bool getWheatEvent();

};

#endif