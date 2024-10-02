#include "Farm.h"

// Constructor
<<<<<<< HEAD
Farm::Farm() : buyPrice(0), sellPrice(0), sellTime(60), timer(NULL){}

=======
Farm::Farm() : buyPrice(0), sellPrice(0), sellTime(60), timer(NULL), optionChoice (""){}
void Farm::applySpeedGrow(){}
void Farm::applyHighYield(){}
>>>>>>> fb062b4a2a2f6a716343968abf04ec88426d0301

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


