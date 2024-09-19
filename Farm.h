#ifndef FARM_H
#define FARM_H

#include <iostream>

class Farm {

    public:
        virtual int sellItem() = 0;
        virtual void buyItem() = 0;
};

#endif