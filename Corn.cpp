#include "Corn.h"

Corn::Corn():Field(){

    this->buyPrice = 20;
    this->sellPrice = 30;
    this->sellTime = 40;

    this->pesticidePrice = 2;
	this->highYieldFactor = 1.2;
    this->highYieldPrice = 2;

}

void Corn::Event(Farmer ourFarmer){
    cout << "A swarm of locusts have attacked you fields" << endl;
    int newCornCount = ourFarmer.getCornCount() * 0.5;
    for (int i = newCornCount; i < ourFarmer.getCornCount(); i++){
        ourFarmer.getCornArray()[i - newCornCount] = ourFarmer.getCornArray()[i];
    }
    ourFarmer.setCornCount(newCornCount);
}

void Corn::applyHighYield(Farmer ourFarmer){

    if (ourFarmer.getMoneyCount() < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    }else{
        int newMoney = ourFarmer.getMoneyCount() - this->highYieldPrice;
        ourFarmer.setMoneyCount(newMoney);
    }

}