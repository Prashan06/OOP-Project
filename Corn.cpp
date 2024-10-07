#include "Corn.h"

Corn::Corn():Field(){

    this->buyPrice = 20;
    this->sellPrice = 30;
    this->sellTime = 40;
	this->highYieldFactor = 1.2;
    this->highYieldPrice = 2;

}

void Corn::Event(Farmer ourFarmer){
    int newCornCount = 0;
    if (getPesticideApplied() == true){
        cout << "A disease has spread throughout the corn, 1/2 of your corn have died." << endl;
        int newCornCount = ourFarmer.getCornCount() * 0.5;
        for (int i = newCornCount; i < ourFarmer.getCornCount(); i++){
        ourFarmer.getCornArray()[i - newCornCount] = ourFarmer.getCornArray()[i];
        }
        ourFarmer.setWheatCount(newCornCount);
    }

    if (getPesticideApplied() == false){
        cout << "A disease has spread throughout the corn, half of your corn have died." << endl;
        int newCornCount = ourFarmer.getCornCount() * 0.5;
        for (int i = newCornCount; i < ourFarmer.getCornCount(); i++){
            ourFarmer.getCornArray()[i - newCornCount] = ourFarmer.getCornArray()[i];
        }
        ourFarmer.setCornCount(newCornCount);
    }
}

void Corn::applyHighYield(Farmer ourFarmer){

    if (ourFarmer.getMoneyCount() < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    } else {
        int newMoney = ourFarmer.getMoneyCount() - this->highYieldPrice;
        ourFarmer.setMoneyCount(newMoney);
        for (int i = 0; i < ourFarmer.getCowCount() < i++;) {
            ourFarmer.getCornArray()[i]->setSellPrice(sellPrice * getHighYieldFactor());
        }
        cout << "highYield successfully applied" << endl;
    }

}