#include "Field.h"

Field::Field(){

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

void Field::applySpeedGrowth(){
    cout << "Do you want to buy the SpeedGrow potion? Y or N " << endl;
    cin >> optionChoice;
    if (optionChoice == "Y"){
        
    }
}

void applyPesticide(){
    cout << "Do you want to buy pesticide? Y or N " << endl;
    if (optionChoice == "Y" && pesticideApplied == false){
        // Note for corn and wheat events, if pesticide applied is true, reduce killing of corn and wheat.
        pesticideAppled = true;
    }
}

Field::~Field(){

}

