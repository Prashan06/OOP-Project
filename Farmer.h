#ifndef FARMER_H
#define FARMER_H

#include <string>
#include <ctime>
#include <chrono>

#include "Wheat.h"
#include "Corn.h"
#include "Cow.h"
#include "Pig.h"
#include "Farm.h"

class Farmer {
    protected:
        
        int money;

        //arrays
        Wheat** wheat;
        Corn** corn;
        Pig** pig;
        Cow** cow;

        //tracking variables for object creation
        int timesWheatPlanted;
        int timesCornPlanted;
        int timesCowsBought;
        int timesPigsBought;

        char farmName[21];
        int cowCount;
        int pigCount;
        int wheatCount;
        int cornCount;
		int timesWheatPlanted;
        int timesCornPlanted;
        int timesCowsBought;
        int timesPigsBought;
   
    public:

        Farmer();
        ~Farmer();

        //getters & setters
        int getMoneyCount();
        void setMoneyCount(int money);
        string getFarmName();
        void setFarmName();
        void getStatus();
        void buyItem();
        int getCropCount ();
        int getAnimalCount ();
        void sellItem();
        int getCowCount();
        int getPigCount();
        int getWheatCount();
        int getCornCount();
        void setCowCount(int cowCount);
        void setPigCount(int pigCount);
        void setWheatCount(int wheatCount);
        void setCornCount(int cornCount);


};
#endif