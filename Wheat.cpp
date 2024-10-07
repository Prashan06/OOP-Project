#include <random>
#include "Wheat.h"

Wheat::Wheat():Field(){

    this->sellPrice = 20;
    this->buyPrice = 10;
    this->sellTime = 30;
	this->highYieldFactor = 1.1;
    this->highYieldPrice = 1;

}

void Wheat::applyHighYield(Farmer ourFarmer){

    if (ourFarmer.getMoneyCount() < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer, try again later" << endl;
    }else{
        int newMoney = ourFarmer.getMoneyCount() - this->highYieldPrice;
        ourFarmer.setMoneyCount(newMoney);
        for (int i = 0; i < ourFarmer.getCowCount() < i++;){
            ourFarmer.getWheatArray()[i]->setSellPrice(sellPrice*getHighYieldFactor());
        }
        cout << "HighYield successfully applied" << endl;
    }

}


void Wheat::Event(Farmer ourFarmer){
    if (ourFarmer.getCowCount() % 10 == 0) {
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 10); // define the range
        int randomNumber = distr(gen);
        if (randomNumber == 1) {
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
    }
}