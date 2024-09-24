#ifndef TOOLS_H
#define TOOLS_H

#include "Farmer.h"

class Tools: public Farmer{

    protected:

        int costPerField;
        bool repaired;

    public:

        void repair();
        void repairedtoFalse();

};

#endif