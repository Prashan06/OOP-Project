#ifndef CORN_H
#define CORN_H

#include "Field.h"
#include "Events.h"

class Corn: public Field, public Events{

    protected:

    public:
        
        Corn();
        void Event();
        void applyHighYield();

};

#endif
