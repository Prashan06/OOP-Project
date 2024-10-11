#ifndef COW_H
#define COW_H

#include "Barn.h"
#include "Events.h"

// This class manages the cows in the farm. This class inherits from Barn and Events.
class Cow: public Barn, public Events{

    protected:

        bool cowEvent;

    public:

        Cow(); //constructor
        void applyHighYield(int* money); //modifies sellPrice & money(from farmer)
        void Event(int* count);

        //getter & setters for cowEvetn
        void setCowEvent(bool cowEvent);
        bool getCowEvent();

};

#endif