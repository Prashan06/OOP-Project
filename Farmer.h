#ifndef FARMER_H
#define FARMER_H

#include <string>
#include <ctime>
#include <chrono>
#include <vector>

#include "Wheat.h"
#include "Corn.h"
#include "Cow.h"
#include "Pig.h"
#include "Farm.h"

class Farmer {
    protected:
    int money;
	wheat_v wheat;
	corn_v corn;
	pig_v pig;
	cow_v cow;
	char farmName[21];
	int cropCount;
	int animalCount;
    Farm farm;

    public:
    void setMoneyCount(int money);
    string getFarmName();
    void setFarmName();
    void getStatus();
    void buyItem();
    void sellItem();
    int getCropCount();
    void setCropCount ();
    int getAnimalCount();
    void setAnimalCount ();
};
#endif