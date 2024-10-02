#include "Field.h"

Field::Field() : speedGrowLevel(0), speedGrowPrice(10), pesticidePrice(20), highYieldFactor(0.2), highYieldPrice(10){

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

void Field::applySpeedGrow(){
    cout << "Do you want to buy the SpeedGrow potion? Y or N " << endl;
    cin >> optionChoice;
    if (optionChoice == "Y"){
        wheat.setSellTime() = wheat.setSellTime;
    }
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

Field::~Field(){

}

