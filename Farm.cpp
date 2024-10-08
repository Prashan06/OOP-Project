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

int Farm::getTimer() {
    return timer;
}

void Farm::setCowCount(int cowCount){
    this->cowCount = cowCount;
}

void Farm::setPigCount(int pigCount){
    this->pigCount = pigCount;
}

void Farm::setWheatCount(int wheatCount){
    this->wheatCount = wheatCount;
}

void Farm::setCornCount(int cornCount){
    this->cornCount = cornCount;
}

int Farm::getCowCount(){
    return cowCount;
}

int Farm::getPigCount(){
    return pigCount;
}

int Farm::getWheatCount(){
    return wheatCount;
}

int Farm::getCornCount(){
    return cornCount;
}

// Destructor.
Farm::~Farm(){}


