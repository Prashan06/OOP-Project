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

typedef vector <Wheat**,time_t> wheat_v;
typedef vector <Corn**, time_t> corn_v;
typedef vector <Pig**,time_t> pig_v;
typedef vector <Cow**,time_t> cow_v;

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
        //Farm farm; should this be here?

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