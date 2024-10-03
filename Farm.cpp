#include "Farm.h"

// Constructor
Farm::Farm() : buyPrice(0), sellPrice(0), sellTime(60), timer(time(0)), optionChoice("") {}


// Sets the buyPrice.
int Farm::setBuyPrice(int buyPrice){
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

// Destructor.
Farm::~Farm(){}


