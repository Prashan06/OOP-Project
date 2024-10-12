#ifndef WHEAT_H
#define WHEAT_H

#include "Field.h"
#include "Events.h"

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