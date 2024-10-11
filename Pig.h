#ifndef PIG_H
#define PIG_H

#include "Barn.h"

class Pig: public Barn, public Events{

    protected:

        bool pigEvent;

    public:

        Pig(); //constructor
        void applyHighYield(int *money); //modified sellPrice & money(from farmer)
        void Event(int* count);

        //getter & setters for pigEvent
        void setPigEvent(bool pigEvent);
        bool getPigEvent();

};

#endif