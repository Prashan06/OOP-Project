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
#include "Barn.h"
#include "Field.h"

class Farmer: public Pig, Corn, Cow, Wheat {
    protected:
        
        int money;
        //arrays
        Wheat** wheat;
        Corn** corn;
        Pig** pig;
        Cow** cow;

        //tracking variables for object creation
        char farmName[21];
		int timesWheatPlanted;
        int timesCornPlanted;
        int timesCowsBought;
        int timesPigsBought;
        int cowCount;
        int pigCount;
        int wheatCount;
        int cornCount;
   
    public:

        Farmer();
        ~Farmer();

        //getters & setters
        int* getMoneyCount();
        void setMoneyCount(int money);
        string getFarmName();
        void setFarmName();
        void getStatus();
        int* getCowCount();
        int* getPigCount();
        int* getWheatCount();
        int* getCornCount();
        void setCowCount(int cowCount);
        void setPigCount(int pigCount);
        void setWheatCount(int wheatCount);
        void setCornCount(int cornCount);
        void executeEvent();
        void buyAnimal();
        void buyCrop();
        void sellAnimal();
        void sellCrop();
        void speedGrowthBought();
        void highYieldBought();

		Cow** getCowArray();
		Pig** getPigArray();
		Wheat** getWheatArray();
		Corn** getCornArray();
		Cow* createNewCow();
		Pig* createNewPig();
		Wheat* createNewWheat();
		Corn* createNewCorn();


};
#endif