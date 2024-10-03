#include "Field.h"

Field::Field() : speedGrowLevel(0), speedGrowPrice(10), pesticidePrice(20), highYieldFactor(1.1), highYieldPrice(25){

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

void Field::applySpeedGrowth(int money){
    cout << "Do you want to buy the SpeedGrowth upgrade? Y or N " << endl;
    cin >> optionChoice;
    while (optionChoice != "Y" && optionChoice != "N") {
        cout << "invalid input! please enter Y or N" << endl;
        cin >> optionChoice;
    }
    if (optionChoice == "Y"){
        sellTime--;
        money = money - speedGrowPrice;
        speedGrowLevel++;
    }
}

// setter for pesticide applied
void Field::setPesticideApplied (bool pesticideApplied) {
    this -> pesticideApplied = pesticideApplied;
}

bool Field::getPesticideApplied(){
    return pesticideApplied;
}

void Field::applyPesticide(){
    cout << "Do you want to buy pesticide? Y or N " << endl;
    if (optionChoice == "Y" && pesticideApplied == false){
        // Note for corn and wheat events, if pesticide applied is true, reduce killing of corn and wheat.
        pesticideApplied = true;
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

Field::~Field(){

}
