#ifndef COW_H
#define COW_H

#include "Barn.h"

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