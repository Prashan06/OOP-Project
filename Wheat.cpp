#include "Wheat.h"

Wheat::Wheat() : Field() {
    this -> sellPrice = 8;
    this -> buyPrice = 10;
    this -> sellTime = 20;
}

void Wheat::applyHighYield(Farmer ourFarmer){
    if (ourFarmer.getMoneyCount() < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    }else{
        int newMoney = ourFarmer.getMoneyCount() - this->highYieldPrice;
        ourFarmer.setMoneyCount(newMoney);
    }
}


void Wheat::Event(Farmer ourFarmer){
    int newWheatCount = 0;
    if (getPesticideApplied() == true){
        cout << "A disease has spread throughout the wheat, 1/4 of your wheat have died." << endl;
        newWheatCount = ourFarmer.getWheatCount() - (ourFarmer.getWheatCount()*(1/4));
        Wheat** tempWheatArray = ourFarmer.getWheatArray();
        for (int i = ourFarmer.getWheatCount() - 1; i >= newWheatCount; i--){
            delete tempWheatArray[i];
            tempWheatArray[i] = nullptr;
        }
        ourFarmer.setWheatCount(newWheatCount); 
    }

    if (getPesticideApplied() == false){
        cout << "A disease has spread throughout the wheat, half of your wheat have died." << endl;
        newWheatCount = ourFarmer.getWheatCount() - ourFarmer.getWheatCount()/2;
        Wheat** tempWheatArray = ourFarmer.getWheatArray();
        for (int i = ourFarmer.getWheatCount() - 1; i >= newWheatCount; i--){
            delete tempWheatArray[i];
            tempWheatArray[i] = nullptr;
        }
        ourFarmer.setWheatCount(newWheatCount);
    }
}