#include <random>
#include "Pig.h"

Pig::Pig() : Barn() {
    this -> sellPrice = 10;
    this -> buyPrice = 15;
    this -> sellTime = 30;
}

void Pig::applyHighYield( Farmer &ourFarmer){
    if (ourFarmer.getMoneyCount() < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    } else {
        int newMoney = ourFarmer.getMoneyCount() - this-> highYieldPrice;
        ourFarmer.setMoneyCount(newMoney);
        for (int i = 0; i < ourFarmer.getCowCount(); i++) {
            ourFarmer.getPigArray()[i]->setSellPrice(sellPrice * getHighYieldFactor());
        }
        cout << "highYield successfully applied" << endl;
    }
}

void Pig::Event(Farmer &ourFarmer){
    if (ourFarmer.getCowCount() % 10 == 0) {
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 10); // define the range
        int randomNumber = distr(gen);
        if (randomNumber == 1) {
            cout << "the demand for pig meat greatly decreased, in order to maintain a healthy flow of pigs " << endl;
            cout << "coming in and out of the farm, the sell price of all currently owned pigs must be reduced by half." << endl;
            for (int i = 0; i < ourFarmer.getPigCount(); i++){
                ourFarmer.getPigArray()[i]->sellPrice = (ourFarmer.getPigArray()[i]->sellPrice) * 0.5;
            }
        }
    }
}

Pig::~Pig(){}