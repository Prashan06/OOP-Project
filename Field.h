#ifndef FIELD_H
#define FIELD_H

#include "Farm.h"

class Field: public Farm{

    protected:

    public:

        Field();
	    ~Field();

        void applySpeedGrowth();

};

#endif