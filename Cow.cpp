#include "Cow.h"

Cow::Cow() : Barn() {
    timer = time(0);
    sellPrice = 10;
    buyPrice = 15;
    sellTime = 30;
}

void Cow::applyHighYield(){
    sellPrice = sellPrice*highYieldFactor;
}

void Cow::Event(){
    cout << "A disease has spread throughout the cows, half of your cows have died." << endl;
    
}

Cow* Cow::createNewCow() {
    Cow* newCow;
    return newCow;
}

Cow::~Cow(){}