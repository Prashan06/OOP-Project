#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include <string>
#include "Events.h"

using namespace std;

class Tools : public Events {
    protected: 
        string cropEnhancer;
        int cropEnhancerLevel;
        string animalFeed;
        int animalFeedLevel;
        int cropEnhancerPrice;
        int animalFeedPrice;
        string optionChoice;

    public: 
        Tools();
        void upgradeCropEnhancer();
        void upgradeAnimalFeed();
        int getCropEnhancerLevel();
        int getAnimalFeedLevel(); 
        

};




#endif