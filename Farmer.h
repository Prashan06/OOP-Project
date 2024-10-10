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

class Farmer: public Pig, public Corn, public Cow, public Wheat {
    protected:
        
        int money;
        int cowCount = 0;
        int pigCount = 0;
        int wheatCount = 0;
        int cornCount = 0;
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
        string product;
   
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
        void buyCorn(Corn**& cornArray, int& cornCount, int amount);
        string getProduct();
        void setProduct(string product);

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