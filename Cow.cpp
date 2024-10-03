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


void Cow::Event(Farmer ourFarmer){
    cout << "A disease has spread throughout the cows, half of your cows have died." << endl;
    Cow** tempCowArray = ourFarmer.getCowArray();
    for (int i = ourFarmer.getCowCount(); i > ourFarmer.getCowCount() - (ourFarmer.getCowCount()/2); i--){
        delete tempCowArray[i];
        ourFarmer.setCowCount(ourFarmer.getCowCount()) = ourFarmer.getCowCount() - 1;
    }
    

}


Cow::~Cow(){}