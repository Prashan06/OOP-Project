#include "Pig.h"

Pig::Pig() : Barn() {
    this -> sellPrice = 10;
    this -> buyPrice = 15;
    this -> sellTime = 30;
}

void Pig::applyHighYield(){
    this -> sellPrice = sellPrice*highYieldFactor;
}

void Pig::Event(Farmer farmer){
    cout << "the demand for pig meat greatly decreased, in order to maintain a healthy flow of pigs " << endl;
    cout << "coming in and out of the farm, the sell price of all currently owned pigs must be reduced by half." << endl;
    for (int i = 0; i < farmer.getPigCount(); i++){
        farmer.getPigArray()[i]->sellPrice == (farmer.getPigArray()[i]->sellPrice) * 0.5;
    }
}

Pig* Pig::createNewPig() {
    Pig* newPig;
    return newPig;
}

Pig::~Pig(){}