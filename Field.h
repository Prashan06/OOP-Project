#ifndef FIELD_H
#define FIELD_H

#include "Farm.h"
#include <iostream>
using namespace std;

class Field: public Farm{

    protected:
	int speedGrowLevel;
    int speedGrowPrice;
	int pesticidePrice;
	bool pesticideApplied;
	float highYieldFactor;
	int highYieldPrice;



    public:
    Field();
    void setSpeedGrowPrice (int speedGrowPrice); 
    int getSpeedGrowPrice ();
    void setPesticidePrice (int pesticidePrice);
    int getPesticidePrice ();
    void setHighYieldFactor(float highYieldFactor);
	int getHighYieldFactor();
    void setHighYieldPrice(int highYieldPrice);
	int getHighYieldPrice();
	void setPesticideApplied (bool pesticideApplied);
	void setSpeedGrowLevel (int speedGrowLevel);
	int getSpeedGrowLevel();
    void applySpeedGrow();
    bool getPesticideApplied ();
	void applyPesticide();
    ~Field();
};

#endif