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
    cout << "A disease has spread throughout the cows, half of your cows have died." << endl;
    farmer.getPigArray();
}

Pig* Pig::createNewPig() {
    Pig* newPig;
    return newPig;
}

Pig::~Pig(){}