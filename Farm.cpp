#include "Farm.h"

Farm::Farm() : buyPrice(0), sellPrice(0), sellTime(60), timer(NULL){}
void Farm::applySpeedGrow(){}
void Farm::applyHighYield(){}
int Farm::setBuyPrice(int buyPrice){}
int Farm::getBuyPrice(){
    return buyPrice;
}
void Farm::setSellPrice(int sellPrice){
    this -> sellPrice = sellPrice;
}
int Farm::getSellPrice(){
    return sellPrice;
}
void Farm::setSellTime(int sellTime){
    this -> sellTime = sellTime;
}
int Farm::getSellTime(){
    return sellTime;
}
Farm::~Farm(){}