#include <random>
#include "Wheat.h"

// Constructor 
Wheat::Wheat():Field(){

    this->sellPrice = 15;
    this->buyPrice = 10;
    this->sellTime = 8;
    this->highYieldPrice = 10;
    this->wheatEvent = false;

}

// This functions sets the wheatHighYieldApplied to true. The code to increase the price of wheat objects is in Farmer
void Wheat::applyHighYield(int *money){
        // Decreases the money and sets cowHighYieldApplied to true.
        *money = *money - this->highYieldPrice;
        wheatHighYieldApplied = true;
}

// This functions sets wheatEvent to true depending on the value of wheatCount. The code to affect the wheat is in Farmer
void Wheat::Event(int* count){
    if (*count % 10 == 0) {
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 10); // define the range
        int randomNumber = distr(gen);
        if (randomNumber == 1) {
            wheatEvent = true;
        }
    }
}

void Wheat::setWheatEvent(bool wheatEvent) {//setter for pigEvent
    this -> wheatEvent = wheatEvent;
}
bool Wheat::getWheatEvent() { // getter for pigEvent.
    return wheatEvent;
}