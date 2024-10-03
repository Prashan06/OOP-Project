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
    Cow** tempCowArray = farmer.getCowArray();
    for (int i = farmer.getCowCount(); i > farmer.getCowCount() - (farmer.getCowCount()/2); i--){
        delete tempCowArray[i];
        farmer.setCowCount(farmer.getCowCount()) = farmer.getCowCount() - 1;
    }
    

}


Cow::~Cow(){}