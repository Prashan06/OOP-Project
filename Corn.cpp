#include <random>
#include "Corn.h"
#include "Farmer.h"


Corn::Corn():Field(){

    this->buyPrice = 20;
    this->sellPrice = 30;
    this->sellTime = 40;
	this->highYieldFactor = 1.2;
    this->highYieldPrice = 2;

}

void Corn::Event(int &count, Cow** cow, Pig** pig, Corn** corn, Wheat** wheat){
    if (count % 10 == 0) {
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 10); // define the range
        int randomNumber = distr(gen);

        if (randomNumber == 1) {
            int newCornCount = 0;
            if (getPesticideApplied() == true){
                cout << "A disease has spread throughout the corn, 1/2 of your corn have died." << endl;
                newCornCount = count * 0.5;
                for (int i = newCornCount; i < count; i++){
                    corn[i - newCornCount] = corn[i];
                }
                count = newCornCount;
            }

            if (getPesticideApplied() == false){
                cout << "A disease has spread throughout the corn, half of your corn have died." << endl;
                int newCornCount = count * 0.5;
                for (int i = newCornCount; i < count; i++){
                    corn[i - newCornCount] = corn[i];
                }
                count = newCornCount;
            }
        }
    }
}

void Corn::applyHighYield(int &money, Corn** corn, int cornCount){

    if (money < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    } else {
        money = money - this->highYieldPrice;
        for (int i = 0; i < cornCount ; i++) {
            corn[i]->setSellPrice(getSellPrice() * getHighYieldFactor());
        }
        cout << "highYield successfully applied" << endl;
    }

}