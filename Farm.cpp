#include "Farm.h"

Farm::Farm() : buyPrice(0), sellPrice(0), sellTime(60), timer(nullptr){}
void Farm::applySpeedGrow(){}
void Farm::applyHighYield(){}
void Farm::setBuyPrice(int buyPrice){
    this -> buyPrice = buyPrice;
}
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