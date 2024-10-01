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

//vector definition
typedef vector <Wheat**,time_t> wheat_v;
typedef vector <Corn**, time_t> corn_v;
typedef vector <Pig**,time_t> pig_v;
typedef vector <Cow**,time_t> cow_v;

class Farmer {

    protected:

        int money;
        char farmName[21];
        int cropCount;
        int animalCount;

        //object arrays
        wheat_v wheat;
        corn_v corn;
        pig_v pig;
        cow_v cow;

        //Farm farm; should this be here?

    public:

        void buyItem();
        void sellItem();
        void getStatus();

        //getters and setters

        void setMoney(int money);
        int getMoney();
        void setFarmName(string farmName);
        string getFarmName();
        void setCropCount();
        int getCropCount ();
        void setAnimalCount();
        int getAnimalCount ();

};

#endif