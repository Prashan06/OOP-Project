#include "Pig.h"

Pig::Pig() : Barn() {
    this -> sellPrice = 10;
    this -> buyPrice = 15;
    this -> sellTime = 30;
}

void Pig::applyHighYield( Farmer ourFarmer){
    if (ourFarmer.getMoneyCount() < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    }else{
        int newMoney = ourFarmer.getMoneyCount() - this->highYieldPrice;
        ourFarmer.setMoneyCount(newMoney);
    }
    this -> sellPrice = sellPrice*highYieldFactor;
}

void Pig::Event(Farmer ourFarmer){
    cout << "the demand for pig meat greatly decreased, in order to maintain a healthy flow of pigs " << endl;
    cout << "coming in and out of the farm, the sell price of all currently owned pigs must be reduced by half." << endl;
    for (int i = 0; i < ourFarmer.getPigCount(); i++){
        ourFarmer.getPigArray()[i]->sellPrice == (ourFarmer.getPigArray()[i]->sellPrice) * 0.5;
    }
}

Pig* Pig::createNewPig() {
    Pig* newPig;
    return newPig;
}

Pig::~Pig(){}