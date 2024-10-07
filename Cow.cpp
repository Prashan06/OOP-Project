#include <random>
#include "Cow.h"

Cow::Cow() : Barn() {
    this -> sellPrice = 10;
    this -> buyPrice = 15;
    this -> sellTime = 30;
}

void Cow::applyHighYield(Farmer ourFarmer){
    if (ourFarmer.getMoneyCount() < highYieldPrice){
        cout << "You do not have enough money to buy high yield" << endl;
    } else {
        int newMoney = ourFarmer.getMoneyCount() - this->highYieldPrice;
        ourFarmer.setMoneyCount(newMoney);
        for (int i = 0; i < ourFarmer.getCowCount() < i++;) {
            ourFarmer.getCowArray()[i]->setSellPrice(sellPrice * getHighYieldFactor());
        }
        cout << "highYield successfully applied" << endl;
    }
}


void Cow::Event(Farmer ourFarmer){
    if (ourFarmer.getCowCount() % 10 == 0) {
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 10); // define the range
        int randomNumber = distr(gen);
        if (randomNumber == 1) {
            cout << "A disease has spread throughout the cows, half of your cows have died." << endl;
            int newCowCount = ourFarmer.getCowCount() * 0.5;
            for (int i = newCowCount; i < ourFarmer.getCowCount(); i++){
                ourFarmer.getCowArray()[i - newCowCount] = ourFarmer.getCowArray()[i];
            }
            ourFarmer.setCowCount(newCowCount);
        }
    }
}


Cow::~Cow(){}