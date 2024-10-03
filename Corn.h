#ifndef CORN_H
#define CORN_H

#include "Field.h"
#include "Events.h"

class Corn: public Field, public Events{

    protected:

    public:
        
        Corn();
        ~Corn();
        void Event(Farmer ourFarmer);
        void applyHighYield();

};

#endif
