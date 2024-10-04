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
}


void Corn::Event(Farmer ourFarmer){
    Corn** tempCornArray = ourFarmer.getCornArray(); 
    int newCornCount = 0;
    if (getPesticideApplied() == true){
        cout << "A disease has spread throughout the corn, 1/4 of your corn have died." << endl;
        newCornCount = ourFarmer.getCornCount() - (ourFarmer.getCornCount()*(1/4));
        for (int i = ourFarmer.getCornCount() - 1; i >= newCornCount; i--){
            delete tempCornArray[i];
            tempCornArray[i] = nullptr;
        }
        ourFarmer.setCornCount(newCornCount); 
    }

    if (getPesticideApplied() == false){
        cout << "A disease has spread throughout the corn, half of your corn have died." << endl;
        newCornCount = ourFarmer.getCornCount() - ourFarmer.getCornCount()/2;
        for (int i = ourFarmer.getCornCount() - 1; i >= newCornCount; i--){
            delete tempCornArray[i];
            tempCornArray[i] = nullptr;
        }
        ourFarmer.setCornCount(newCornCount);
    }
}