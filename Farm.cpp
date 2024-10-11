#include "Farm.h"

// Constructor
Farm::Farm() : buyPrice(0), sellPrice(0), sellTime(60), timer(time(0)), optionChoice("") {}


// Sets the buyPrice.
void Farm::setBuyPrice(int buyPrice){
    this -> buyPrice = buyPrice;
}

// Returns the buyPrice
int Farm::getBuyPrice(){
    return buyPrice;
}

// sets the sellPrice
void Farm::setSellPrice(int sellPrice){
    this -> sellPrice = sellPrice;
}

// returns the sellPrice
int Farm::getSellPrice(){
    return sellPrice;
}

// sets the sellTime
void Farm::setSellTime(int sellTime){
    this -> sellTime = sellTime;
}

// returns the sellTime.
int Farm::getSellTime(){
    return sellTime;
}

// returns the timer.
int Farm::getTimer() {
    return timer;
}

// returns barnSpeedGrowthApplied
bool Farm::getBarnSpeedGrowthApplied(){
    return barnSpeedGrowthApplied;
}

// returns fieldSpeedGrowthApplied
bool Farm::getFieldSpeedGrowthApplied(){
    return fieldSpeedGrowthApplied;
}

// sets barnSpeedGrowthApplied
void Farm::setBarnSpeedGrowthApplied(bool barnSpeedGrowthApplied){
    this -> barnSpeedGrowthApplied = barnSpeedGrowthApplied;
}

// returns fieldSpeedGrowthApplied
void Farm::setFieldSpeedGrowthApplied(bool fieldSpeedGrowthApplied){
    this -> fieldSpeedGrowthApplied = fieldSpeedGrowthApplied;
}

// returns pigHighYieldApplied
bool Farm::getPigHighYieldApplied(){
    return pigHighYieldApplied;
}

// returns cowHighYieldApplied
bool Farm::getCowHighYieldApplied(){
    return cowHighYieldApplied;
}

// returns wheatHighYieldApplied
bool Farm::getWheatHighYieldApplied(){
    return wheatHighYieldApplied;
}

// returns cornHighYieldApplied
bool Farm::getCornHighYieldApplied(){
    return cornHighYieldApplied;
}

// sets pigHighYieldApplied
void Farm::setPigHighYieldApplied(bool pigHighYieldApplied){
    this -> pigHighYieldApplied = pigHighYieldApplied;
}

// sets cowHighYieldApplied
void Farm::setCowHighYieldApplied(bool cowHighYieldApplied){
    this -> cowHighYieldApplied = cowHighYieldApplied;
}

// sets wheatHighYieldApplied
void Farm::setWheatHighYieldApplied(bool wheatHighYieldApplied){
    this -> wheatHighYieldApplied = wheatHighYieldApplied;
}

// sets cornHighYieldApplied
void Farm::setCornHighYieldApplied(bool cornHighYieldApplied){
    this -> cornHighYieldApplied = cornHighYieldApplied;
}

// This fucntions detemines if the object (cow,corn,wheat,pig) is ready to sell.
bool Farm:: isReadyToSell (){
    // gets time difference between current time and when the object was created.
    int getDuration = time(NULL) - timer;
    // determines if the time difference is greater than the sell time and returns a boolean.
    if (getDuration > getSellTime()){
        return true;
    }else {
        return false;
    }
}

// applySpeedGrowth and HighYield. These are defined in class that inherit Farm.
void Farm::applySpeedGrowth(int* money) {};
void Farm::applyHighYield(int* money) {};
