#ifndef BARN_H
#define BARN_H

#include "Farm.h"

class Barn: public Farm {

    protected:
        int speedGrowPrice;
	    float highYieldFactor;
	    int highYieldPrice;
	    int speedGrowLevel;

    public:
    Barn();
    void setHighYieldFactor(float highYieldFactor);
	int getHighYieldFactor();
    void setHighYieldPrice(int highYieldPrice);
	int getHighYieldPrice();
    void setSpeedGrowPrice (int speedGrowPrice);
    int getSpeedGrowPrice ();
    void applySpeedGrowth(Farmer farmer);
    void setSpeedGrowLevel (int speedGrowLevel);
	int getSpeedGrowLevel();
    ~Barn();
};

#endif