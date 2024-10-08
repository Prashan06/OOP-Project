#include <random>
#include "Wheat.h"
#include "Farmer.h"

Wheat::Wheat():Field(){

    this->sellPrice = 20;
    this->buyPrice = 10;
    this->sellTime = 30;
	this->highYieldFactor = 1.1;
    this->highYieldPrice = 1;

}

void Wheat::applyHighYield(int &money, int &wheatCount, Wheat** wheat){

    if (money < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer, try again later" << endl;
    } else {
        money = money - this->highYieldPrice;
        for (int i = 0; i < wheatCount; i++){
            wheat[i]->setSellPrice(getSellPrice() * getHighYieldFactor());
        }
        cout << "HighYield successfully applied" << endl;
    }

}

void Wheat::Event(int &count, Cow** cow, Pig** pig, Corn** corn, Wheat** wheat){
    if (count % 10 == 0) {
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 10); // define the range
        int randomNumber = distr(gen);
        if (randomNumber == 1) {
            int newWheatCount = 0;
            if (getPesticideApplied() == true){
                cout << "A disease has spread throughout the wheat, 1/4 of your wheat have died." << endl;
                newWheatCount = count * 0.25;
                for (int i = newWheatCount; i < count; i++){
                    wheat[i - newWheatCount] = wheat[i];
                }
                count = newWheatCount;
            }

            if (getPesticideApplied() == false){
                cout << "A disease has spread throughout the wheat, half of your wheat have died." << endl;
                newWheatCount = count * 0.5;
                for (int i = newWheatCount; i < count; i++){
                    wheat[i - newWheatCount] = wheat[i];
                }
                count = newWheatCount;
            }
        }
    }
}