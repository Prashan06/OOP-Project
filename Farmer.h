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
<<<<<<< HEAD
        
        int money;

        //arrays
        Wheat** Wheat[];
        Corn** Corn[];
        Pig** Pig[];
        Cow** Cow[];

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
   
    public:

        Farmer();
        ~Farmer();

        //getters & setters
        int getMoneyCount();
        void setMoneyCount(int money);
        string getFarmName();
        Void setFarmName();
        Void getStatus();
        Void buyItem();
        Int getCropCount ();
        Int getAnimalCount ();
        void sellItem();
        int getCowCount()
        int getPigCount();
        int getWheatCount();
        int getCornCount();
        Void setCowCount(int cowCount);
        Void setPigCount(int pigCount);
        Void setWheatCount(int wheatCount);
        Void setCornCount(int cornCount);
        int timesWheatPlanted;
        int timesCornPlanted;
        int timesCowsBought;
        int timesPigsBought;
         int timesWheatPlanted;
        int timesCornPlanted;
        int timesCowsBought;
        int timesPigsBought;
=======
	int money;
	Wheat** wheat;
	Corn** corn;
	Pig** pig;
	Cow** cow;
	char farmName[21];
	int cowCount;
	int pigCount;
	int wheatCount;
	int cornCount;
	Farm farm;
    public:
    Farmer();
	int getMoneyCount();
	void setMoneyCount(int money);
	string getFarmName();
	Void setFarmName();
	Void getStatus();
	Void buyItem();
    Int getCropCount ();
    Int getAnimalCount ();
	void sellItem();
	int getCowCount()
	int getPigCount();
	int getWheatCount();
	int getCornCount();
	Void setCowCount(int cowCount);
	Void setPigCount(int pigCount);
	Void setWheatCount(int wheatCount);
	Void setCornCount(int cornCount);
	~Farmer();
>>>>>>> 2df9fa5a755870bd951059984995c9a5a51918c0

};
#endif