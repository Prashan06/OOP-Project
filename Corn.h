#ifndef CORN_H
#define CORN_H

#include "Field.h"
#include "Events.h"
#include "Wheat.h"
#include "Cow.h"
#include "Pig.h"



class Corn: public Field, public Events {

    protected:
         bool cornEvent;
    public:
        
        Corn();
        ~Corn();
        void Event(int* count);
        void applyHighYield(int* money);
        void setCornEvent(bool cornEvent);
        bool getCornEvent();

};

#endif
