#include "Field.h"

// Constructor
Field::Field():Farm(){
    
this->speedGrowLevel = 0;
this->speedGrowPrice = 30; 
this->pesticidePrice = 5;
this->highYieldFactor = 1.1;
this->highYieldPrice = 25;

}

// setter for SpeedGrowPrice
void Field::setSpeedGrowPrice (int speedGrowPrice){
    this -> speedGrowPrice = speedGrowPrice;
}

// getter for speedGrowPrice.
int Field::getSpeedGrowPrice (){
    return speedGrowPrice;
}

// Setter for pesticidePice.
void Field::setPesticidePrice (int pesticidePrice){
    this -> pesticidePrice = pesticidePrice;
}

// getter for pesticidePrice.
int Field::getPesticidePrice (){
    return pesticidePrice;
}

// setter for HighYieldFactor.
void Field::setHighYieldFactor(float highYieldFactor){
    this -> highYieldFactor = highYieldFactor;
}

// getter for highYieldFactor
float Field::getHighYieldFactor(){
    return highYieldFactor;
}

// setter for highYieldPrice.
void Field::setHighYieldPrice(int highYieldPrice){
    this -> highYieldPrice = highYieldPrice;
}

// getter for highYieldPrice.
int Field::getHighYieldPrice(){
    return highYieldPrice;
}


void Field::applySpeedGrowth(int* money){
    // Below ensures the user has enough money to buy speedGrow.
    if (*money < speedGrowPrice){
        cout << "You do not have enough money to buy the SpeedGrowth update, try again later" << endl;
    }else{
        // sets speedGrowApplied to true and decreases the money the user has.
        *money = *money - speedGrowPrice;
        speedGrowLevel++;
        speedGrowApplied = true;
    }
}

// setter for pesticide applied
void Field::setPesticideApplied (bool pesticideApplied) {
    this -> pesticideApplied = pesticideApplied;
}


// getter for pesticideApplied.
bool Field::getPesticideApplied(){
    return pesticideApplied;
}

// setter for speed grow level
void Field::setSpeedGrowLevel (int speedGrowLevel) {
    this -> speedGrowLevel = speedGrowLevel;
}

// getter speed grow level
int Field::getSpeedGrowLevel() {
    return speedGrowLevel;
}

//setter for speedGrowApplied
void Field::setSpeedGrowApplied(bool speedGrowApplied){
    this->speedGrowApplied = speedGrowApplied;
}

//getter for speedGrowApplied
bool Field::getSpeedGrowApplied(){
    return speedGrowApplied;
}