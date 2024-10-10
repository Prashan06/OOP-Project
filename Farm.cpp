#include "Farm.h"

// Constructor
Farm::Farm() : buyPrice(0), sellPrice(0), sellTime(60), timer(time_t(0)), optionChoice("") {}


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

int Farm::getTimer() {
    return timer;
}

bool Farm::getBarnSpeedGrowthApplied(){
    return barnSpeedGrowthApplied;
}
bool Farm::getFieldSpeedGrowthApplied(){
    return fieldSpeedGrowthApplied;
}
void Farm::setBarnSpeedGrowthApplied(bool barnSpeedGrowthApplied){
    this -> barnSpeedGrowthApplied = barnSpeedGrowthApplied;
}
void Farm::setFieldSpeedGrowthApplied(bool fieldSpeedGrowthApplied){
    this -> fieldSpeedGrowthApplied = fieldSpeedGrowthApplied;
}
bool Farm::getPigHighYieldApplied(){
    return pigHighYieldApplied;
}
bool Farm::getCowHighYieldApplied(){
    return cowHighYieldApplied;
}
bool Farm::getWheatHighYieldApplied(){
    return wheatHighYieldApplied;
}
bool Farm::getCornHighYieldApplied(){
    return cornHighYieldApplied;
}

int Farm::getSellReadyTime() {
    return sellReadyTime;
}

void Farm::setPigHighYieldApplied(bool pigHighYieldApplied){
    this -> pigHighYieldApplied = pigHighYieldApplied;
}
void Farm::setCowHighYieldApplied(bool cowHighYieldApplied){
    this -> cowHighYieldApplied = cowHighYieldApplied;
}
void Farm::setWheatHighYieldApplied(bool wheatHighYieldApplied){
    this -> wheatHighYieldApplied = wheatHighYieldApplied;
}
void Farm::setCornHighYieldApplied(bool cornHighYieldApplied){
    this -> cornHighYieldApplied = cornHighYieldApplied;
}

void Farm::applySpeedGrowth(int* money) {};
void Farm::applyHighYield(int* money) {};


