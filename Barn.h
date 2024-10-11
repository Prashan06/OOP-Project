#ifndef BARN_H
#define BARN_H

#include "Farm.h"


// This class has functions and attributes that manage the barn. This class inherits from Farm and is inherited by the cow and pig classes.
class Barn: public Farm {

    protected:

        int speedGrowPrice;
	    float highYieldFactor;
	    int highYieldPrice;
	    int speedGrowLevel;
        bool speedGrowApplied;

    public:

        Barn(); // Constructor 
        void setHighYieldFactor(float highYieldFactor);
        float getHighYieldFactor(); 
        void setHighYieldPrice(int highYieldPrice); 
        int getHighYieldPrice();
        void setSpeedGrowPrice (int speedGrowPrice);
        int getSpeedGrowPrice ();
        void applySpeedGrowth(int* money);
        void setSpeedGrowLevel (int speedGrowLevel);
        int getSpeedGrowLevel();
        void setSpeedGrowApplied(bool speedGrowApplied);
        bool getSpeedGrowApplied();
    
};

#endif