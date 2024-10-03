#ifndef WHEAT_H
#define WHEAT_H

#include "Field.h"
#include "Events.h"

class Wheat: public Field, public Events{

    protected:

    public:
        
        Wheat();
        ~Wheat();
        void Event(Farmer ourFarmer);
        void applyHighYield();

};

#endif