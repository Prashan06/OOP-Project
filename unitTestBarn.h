#ifndef UNITTESTBARN_H
#define UNITTESTBARN_H

#include "Barn.h"
#include "Farmer.h"
 
using namespace std;

class unitTestBarn{

    protected:

    void testBarn(){

        Barn testBarn;

        void setHighYieldFactor(float highYieldFactor);
        int getHighYieldFactor();
        void setHighYieldPrice(int highYieldPrice);
        int getHighYieldPrice();
        void setSpeedGrowPrice (int speedGrowPrice);
        int getSpeedGrowPrice ();
        void applySpeedGrowth(int* money);
        void setSpeedGrowLevel (int speedGrowLevel);
        int getSpeedGrowLevel();

    }

    public:

        void runTests(){
            testBarn();
        }

};

#endif