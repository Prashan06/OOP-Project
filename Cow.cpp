#include "Cow.h"

Cow::Cow() : Barn() {
    this -> sellPrice = 10;
    this -> buyPrice = 15;
    this -> sellTime = 30;
}

void Cow::applyHighYield(Farmer ourFarmer){
    if (ourFarmer.getMoneyCount() < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    }else{
        int newMoney = ourFarmer.getMoneyCount() - this->highYieldPrice;
        ourFarmer.setMoneyCount(newMoney);
    }
}


void Cow::Event(Farmer farmer){
    cout << "A disease has spread throughout the cows, half of your cows have died." << endl;
    farmer.setCowCount(farmer.getCowCount() / 2);
    for (int i = 0; i < *farmer.getCowCount(); i++){
        farmer.setCowCount(farmer.getCowCount()) = farmer.getCowCount() - 1;
    }
    

}


Cow::~Cow(){}