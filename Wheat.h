#ifndef WHEAT_H
#define WHEAT_H

#include "Field.h"

class Wheat: public Field, public Events{

    protected:

    //all attributes inherited

    public:
        
        Wheat();
        ~Wheat();
        void Event(Farmer ourFarmer);
        void applyHighYield(Farmer ourFarmer);

};

#endif