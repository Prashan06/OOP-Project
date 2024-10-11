#ifndef FIELD_H
#define FIELD_H

#include "Farm.h"

// This class has attributed and functions that manage the field. This class inherits from Farm and is inherited by Corn and Wheat.
class Field: public Farm {

    protected:

        int speedGrowLevel;
        int speedGrowPrice;
        int pesticidePrice;
        bool pesticideApplied;
        bool speedGrowApplied;
        float highYieldFactor;
        int highYieldPrice;

    public:

        Field();
        void setSpeedGrowPrice (int speedGrowPrice); 
        int getSpeedGrowPrice ();
        void setPesticidePrice (int pesticidePrice);
        int getPesticidePrice ();
        void setHighYieldFactor(float highYieldFactor);
        float getHighYieldFactor();
        void setHighYieldPrice(int highYieldPrice);
        int getHighYieldPrice();
        void setPesticideApplied (bool pesticideApplied);
        void setSpeedGrowLevel (int speedGrowLevel);
        int getSpeedGrowLevel();
        void applySpeedGrowth(int* money);
        bool getPesticideApplied ();
        void applyPesticide(int* money);
        void setSpeedGrowApplied(bool speedGrowApplied);
        bool getSpeedGrowApplied();
};

#endif