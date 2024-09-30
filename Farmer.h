#ifndef FARMER_H
#define FARMER_H

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>

#include "Wheat.h"
#include "Corn.h"
#include "Cows.h"
#include "Pigs.h"
#include "Farm.h"

typedef vector <Wheat**> wheat_v;
typedef vector <Corn**> corn_v;
typedef vector <Pigs**> pig_v;
typedef vector <Cows**> cow_v;

using namespace std;

// Farmer Class 
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
    Farmer();
    int getMoneyCount();
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