#ifndef WHEAT_H
#define WHEAT_H

#include "Field.h"
#include "Events.h"
#include "Farmer.h"

class Wheat: public Field, public Events {

    protected:

    //all are attributes inherited from Field & Events classes

    public:
        
        Wheat();
        ~Wheat();
        void Event(int &wheatCount, Wheat** wheat);
        void applyHighYield(int &money, int &wheatCount, Wheat** wheat);

};

#endif