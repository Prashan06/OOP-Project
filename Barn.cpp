#include "Barn.h"
#include <iostream>

using namespace std;

// constructor
Barn::Barn() : Farm() ,speedGrowPrice(15), highYieldFactor(1.1), highYieldPrice(25), speedGrowLevel(0) {}

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
void Barn::applySpeedGrowth(Farmer &farmer) {
    cout << "Do you want to buy the SpeedGrowth upgrade? Y or N " << endl;
    cin >> optionChoice;
    while (optionChoice != "Y" && optionChoice != "N") {
        cout << "invalid input! please enter Y or N" << endl;
        cin >> optionChoice;
    }
    if (optionChoice == "Y"){
        farmer.setMoneyCount(farmer.getMoneyCount()-speedGrowPrice);
        for (int i = 0; i < (farmer.getCowCount()) ; i++) {
            farmer.getCowArray()[i]->setSellTime(sellTime--);
            farmer.getPigArray()[i]->setSellTime(sellTime--);
        }
        speedGrowLevel++;
        cout << "speedGrowth successfully applied" << endl;
    }
}


// destructor
Barn::~Barn(){

}
