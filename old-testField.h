#ifndef FIELD_H
#define FIELD_H

#include "Farm.h"

class Field{

        protected:

        int cropPlantPrice; // modified in wheat and corn classes

        int cropSellPrice; // modified in wheat and corn classes

        float cropGrowth; // tracks current stage of growth, is a percentage
 
        int cropGrowthRate; // modified in wheat and corn classes

        int fertilizerPrice; // price to fertilize 
        int PesticidePrice;     

        float fertilizerPercentage; // tracks how much fertilizer the field has received, is a percentage
        float pesticidePercentage; // tracks how much pesticide the field has received, is a percentage

    public:

        Field();

        virtual void Fertilzation(); // Increases fertilizationPercentage, must not exceed 100%
        virtual void Pesticide(); // Increases pesticidePercentage, must not exceed 100%

        virtual void Grow(); // uses cropGrowthRate & fertilizationPercentage to increase cropGowth, notifies when a crop is fully grown

        // set & get functions

        void setCropPlantPrice();
        int getCropPlantPrice();
        
        void setCropSellPrice();
        int getCropSellPrice();

        void setCropGrowth();
        int getCropGrowth();

        void setFertilizerPrice();
        int getFertilizerPrice();

        void setPesticidePrice();
        int getPesticidePrice();

        void setFertilizerPercentage();
        float getFertilizerPercentage();

        void setFertilizerPercentage();
        float getFertilizerPercentage();

        int sellItem(); // inherited from Farm

};

#endif