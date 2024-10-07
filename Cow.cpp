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
    cout << "A disease has spread throughout the cows, half of your cows have died." << endl;
    int newCowCount = ourFarmer.getCowCount() * 0.5;
    for (int i = newCowCount; i < ourFarmer.getCowCount(); i++){
        ourFarmer.getCowArray()[i - newCowCount] = ourFarmer.getCowArray()[i];
    }
    ourFarmer.setCowCount(newCowCount);
}


Cow::~Cow(){}