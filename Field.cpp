#include "Field.h"

Field::Field():Farm(){
    
this->speedGrowLevel = 0;
this->speedGrowPrice = 10; 
this->pesticidePrice = 10;
this->highYieldFactor = 1.1;
this->highYieldPrice = 25;

}

void Field::setSpeedGrowPrice (int speedGrowPrice){
    this -> speedGrowPrice = speedGrowPrice;
}
int Field::getSpeedGrowPrice (){
    return speedGrowPrice;
}
void Field::setPesticidePrice (int pesticidePrice){
    this -> pesticidePrice = pesticidePrice;
}
int Field::getPesticidePrice (){
    return pesticidePrice;
}
void Field::setHighYieldFactor(float highYieldFactor){
    this -> highYieldFactor = highYieldFactor;
}
int Field::getHighYieldFactor(){
    return highYieldFactor;
}
void Field::setHighYieldPrice(int highYieldPrice){
    this -> highYieldPrice = highYieldPrice;
}
int Field::getHighYieldPrice(){
    return highYieldPrice;
}

void Field::applySpeedGrowth(int* money){
    cout << "Do you want to buy the SpeedGrowth upgrade? Y or N " << endl;
    cin >> optionChoice;
    while (optionChoice != "Y" && optionChoice != "N") {
        cout << "invalid input! please enter Y or N" << endl;
        cin >> optionChoice;
    }
    if (optionChoice == "Y"){
        if (*money < speedGrowPrice){
            cout << "You do not have enough money to buy the SpeedGrowth update, try again later" << endl;
        }else{
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

bool Field::getPesticideApplied(){
    return pesticideApplied;
}

void Field::applyPesticide(int* money){
    cout << "Do you want to buy pesticide? Y or N " << endl;
    if (optionChoice == "Y" && pesticideApplied == false){
        if (*money < pesticidePrice){
            cout << "You do not have enough money to buy pesticide, try again later" << endl;
        }else{
        // Note for corn and wheat events, if pesticide applied is true, reduce killing of corn and wheat.
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