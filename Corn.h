#ifndef CORN_H
#define CORN_H

#include "Field.h"
#include "Events.h"
#include "Farmer.h"



class Corn: public Field, public Events {

    protected:

    //all attributes inherited from Field

    public:
        
        Corn();
        ~Corn();
        void Event(int &count, Cow** cow, Pig** pig, Corn** corn, Wheat** wheat);
        void applyHighYield(int &money, Corn** corn, int cornCount);

};

#endif
