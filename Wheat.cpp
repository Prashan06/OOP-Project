#include <random>
#include "Wheat.h"

// Constructor 
Wheat::Wheat():Field(){

    this->sellPrice = 15;
    this->buyPrice = 10;
    this->sellTime = 8;
    this->highYieldPrice = 10;

}


void Wheat::applyHighYield(int *money){

    if (*money < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer, try again later" << endl; // checks whether the player has enough money to execute the function
    } else {
        // Decreases the money and sets cowHighYieldApplied to true.
        *money = *money - this->highYieldPrice;
        wheatHighYieldApplied = true;
        cout << "HighYield successfully applied" << endl;
    }

}

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

void Wheat::setWheatEvent(bool wheatEvent) { // setter for wheatEvent
    this -> wheatEvent = wheatEvent;
}
bool Wheat::getWheatEvent() {// getter for wheatEvent.
    return wheatEvent;
}