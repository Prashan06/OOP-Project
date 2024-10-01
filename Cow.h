#ifndef COW_H
#define COW_H

#include "Barn.h"
#include "Events.h"

class Cow: public Barn, public Events{

    protected:

    public:

        Cow();
        void applyHighYield();

};

#endif