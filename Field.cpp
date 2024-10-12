#include "Field.h"

// Constructor
Field::Field():Farm(){
    
this->speedGrowLevel = 0;
this->speedGrowPrice = 30; 
this->pesticidePrice = 10;
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
            cout << "You do not have enough money to buy the SpeedGrowth update, try again later" << endl;
        }else{
            // sets speedGrowApplied to true and decreases the money the user has.
            *money = *money - speedGrowPrice;
            speedGrowLevel++;
            speedGrowApplied = true;
            cout << "speedGrowth for field successfully applied" << endl;
        }
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

void Field::applyPesticide(int* money){
    // Ask user if they want to apply pesticide and put their response into optionChoice.
    cout << "Do you want to buy pesticide? Y or N " << endl;
    if (optionChoice == "Y" && pesticideApplied == false){
        // Check to see if the user has enough money to buy pesticide.
        if (*money < pesticidePrice){
            cout << "You do not have enough money to buy pesticide, try again later" << endl;
        }else{
        // Note for corn and wheat events, if pesticide applied is true, reduce killing of corn and wheat.
        // sets pesticideApplied to true and decreases money.
        pesticideApplied = true;
        *money = *money - pesticidePrice;
        }
    }
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