#ifndef CORN_H
#define CORN_H

#include "Field.h"

class Corn: public Field, public Events{

    protected:

    public:
        
        Corn();
        ~Corn();
        void Event(Farmer ourFarmer);
        void applyHighYield(Farmer ourFarmer);

};

#endif
