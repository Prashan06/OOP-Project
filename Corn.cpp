#include "Corn.h"

Corn::Corn() : Field() {
    this -> sellPrice = 15;
    this -> buyPrice = 10;
    this -> sellTime = 35;
}

void Corn::applyHighYield(Farmer ourFarmer){
    if (ourFarmer.getMoneyCount() < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    }else{
        int newMoney = ourFarmer.getMoneyCount() - this->highYieldPrice;
        ourFarmer.setMoneyCount(newMoney);
    }
    this -> sellPrice = sellPrice * getHighYieldFactor();
}


void Corn::Event(Farmer ourFarmer){ 
    if (getPesticideApplied() == true){
        cout << "A disease has spread throughout the corn, your corn growth rate has increased by 10 seconds" << endl;
        this -> sellTime = this -> sellTime + 10;
    }

    if (getPesticideApplied() == false){
        cout << "A disease has spread throughout the corn, your corn growth rate has increased by 20 seconds" << endl;
        this -> sellTime = this -> sellTime + 20;
    }
}