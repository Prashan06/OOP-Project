#include "Wheat.h"

Wheat::Wheat() : Field() {
    this->sellPrice = 8;
    this->buyPrice = 10;
    this->sellTime = 20;
    this-> pesticidePrice = 2;
	this-> highYieldFactor = 1.2;
    this-> highYieldPrice = 2;
}

void Wheat::applyHighYield(Farmer ourFarmer){
    if (ourFarmer.getMoneyCount() < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    } else {
        int newMoney = ourFarmer.getMoneyCount() - this->highYieldPrice;
        ourFarmer.setMoneyCount(newMoney);
        for (int i = 0; i < ourFarmer.getCowCount() < i++;) {
            ourFarmer.getWheatArray()[i]->setSellPrice(sellPrice * getHighYieldFactor());
        }
        cout << "highYield successfully applied" << endl;
    }
}


void Wheat::Event(Farmer ourFarmer){
    int newWheatCount = 0;
    if (getPesticideApplied() == true){
        cout << "A disease has spread throughout the wheat, 1/4 of your wheat have died." << endl;
        int newWheatCount = ourFarmer.getWheatCount() * 0.25;
        for (int i = newWheatCount; i < ourFarmer.getWheatCount(); i++){
        ourFarmer.getWheatArray()[i - newWheatCount] = ourFarmer.getWheatArray()[i];
        }
        ourFarmer.setWheatCount(newWheatCount);
    }

    if (getPesticideApplied() == false){
        cout << "A disease has spread throughout the wheat, half of your wheat have died." << endl;
        int newWheatCount = ourFarmer.getWheatCount() * 0.5;
        for (int i = newWheatCount; i < ourFarmer.getWheatCount(); i++){
            ourFarmer.getWheatArray()[i - newWheatCount] = ourFarmer.getWheatArray()[i];
        }
        ourFarmer.setWheatCount(newWheatCount);
    }
}