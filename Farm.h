#ifndef FARM_H
#define FARM_H

#include <iostream>

class Farm {

    public:
        virtual void sellItem() = 0;
        virtual void buyItem() = 0;
};

#endif