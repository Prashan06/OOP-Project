#include "Cow.h"

Cow::Cow() : Barn() {
    timer = time(0);
    this -> sellPrice = 10;
    this -> buyPrice = 15;
    this -> sellTime = 30;
}

void Cow::applyHighYield(){
    this -> sellPrice = sellPrice*highYieldFactor;
}

void Cow::Event(Farmer farmer){
    cout << "A disease has spread throughout the cows, half of your cows have died." << endl;
    
}

Cow* Cow::createNewCow() {
    Cow* newCow;
    return newCow;
}

Cow::~Cow(){}