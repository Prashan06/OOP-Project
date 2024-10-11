#ifndef CORN_H
#define CORN_H

#include "Field.h"

class Corn: public Field, public Events{

    protected:

        bool cornEvent;

    public:
        
        Corn(); //constructor 
        void Event(int* count); 
        void applyHighYield(int* money); //modifies sellPrice & money (in farmer)

        //getters and setters fo cornEvent
        void setCornEvent(bool cornEvent);
        bool getCornEvent();

};

#endif
