#include "Barn.h"
#include <iostream>

using namespace std;

// constructor
Barn::Barn() : Farm(), speedGrowPrice(15), highYieldFactor(1.1), highYieldPrice(25), speedGrowLevel(0) {}

// setter for highYieldFactor
void Barn::setHighYieldFactor(float highYieldFactor) {
    this -> highYieldFactor = highYieldFactor;
}

// getter for highYieldFactor
float Barn::getHighYieldFactor() {
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
void Barn::applySpeedGrowth(int* money) {
    // Asks user if they want to buy speed grow and then put their response into optionChoice.
    cout << "Do you want to buy the SpeedGrowth upgrade? Y or N " << endl;
    cin >> optionChoice;
    // Only "Y" and "N" and accepted. Otherwise, ask user for another input.
    while (optionChoice != "Y" && optionChoice != "N") {
        cout << "invalid input! please enter Y or N" << endl;
        cin >> optionChoice;
    }
    if (optionChoice == "Y"){
        // Below ensures the user has enough money to buy speedGrow.
        if (*money < speedGrowPrice){
            cout << "You do not have enough money to buy the speedGrowth update, try again later" << endl;
        }else{
        // sets speedGrowApplied to true and decreases the money the user has.
        speedGrowApplied = true;
        speedGrowLevel++;
        *money = *money - speedGrowPrice;
        cout << "Speed growth for barn successfully applied. " << endl;
        }
    }
}

//getter for speedGrowApplied
bool Barn::getSpeedGrowApplied(){
    return speedGrowApplied;
}

//setter for speedGrowApplied
void Barn::setSpeedGrowApplied(bool speedGrowApplied){
    this->speedGrowApplied = speedGrowApplied;
}
