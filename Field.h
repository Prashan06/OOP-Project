#ifndef FIELD_H
#define FIELD_H

#include "Farm.h"

class Field: public Farm {

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
        void applySpeedGrowth(int* money);
        bool getPesticideApplied ();
        void applyPesticide(int* money);
};

#endif