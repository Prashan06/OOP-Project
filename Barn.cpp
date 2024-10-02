#include "Barn.h"
#include <iostream>

using namespace std;

// constructor
Barn::Barn() : speedGrowPrice(0), highYieldFactor(0), highYieldPrice(0), speedGrowLevel(0) {}

// setter for highYieldFactor
void Barn::setHighYieldFactor(float highYieldFactor) {
    this -> highYieldFactor = highYieldFactor;
}

// getter for highYieldFactor
int Barn::getHighYieldFactor() {
    return highYieldFactor;
}

// setter for highYieldPrice
void Barn::setHighYieldPrice(int highYieldPrice) {
    this -> highYieldPrice = highYieldPrice;
}

// getter for highYieldPrice
int Barn::getHighYieldPrice() {
    return highYieldPrice;
}

// setter for speedGrowPrice
void Barn::setSpeedGrowPrice (int speedGrowPrice) {
    this -> speedGrowPrice = speedGrowPrice;
}

// getter for speedGrowPrice
int Barn::getSpeedGrowPrice () {
    return speedGrowPrice;
};

// setter for speedGrowPrice
void Barn::setSpeedGrowLevel(int speedGrowLevel) {
    this -> speedGrowLevel = speedGrowLevel;
}

// getter for speedGrowPrice
int Barn::getSpeedGrowLevel() {
    return speedGrowLevel;
}

// method to apply the speed growth boost to the farmers items
void Barn::applySpeedGrowth(int money) {
    cout << "Do you want to buy the SpeedGrowth upgrade? Y or N " << endl;
    cin >> optionChoice;
    while (optionChoice != "Y" && optionChoice != "N") {
        cout << "invalid input! please enter Y or N" << endl;
        cin >> optionChoice;
    }
    if (optionChoice == "Y"){
        money = money-speedGrowPrice;
        speedGrowLevel++;
        // will need to do for every element in array sellTime--;
    }
}


// destructor
Barn::~Barn(){

}
