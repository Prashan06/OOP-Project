#include <random>
#include "Corn.h"

 //constructor
Corn::Corn():Field(){
    this->buyPrice = 13;
    this->sellPrice = 15;
    this->sellTime = 5;
    this->highYieldPrice = 10;

}

// This functions sets cornEvent to true depending on the value of cornCount. The code to affect the corn is in Farmer
void Corn::Event(int* count){

    if (*count % 5 == 0){

        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 20); // define the range
        int randomNumber = distr(gen);

        if (randomNumber == 1) { 
           this -> cornEvent = true;
           setCornEvent(cornEvent);
        }
    }
}

// This functions sets the cornHighYieldApplied to true. The code to increase the price of corn objects is in Farmer.
void Corn::applyHighYield(int* money){

        // Decreases tghe money and sets cornHighYieldApplied to true.
        *money = (*money) - this->highYieldPrice;
        cornHighYieldApplied = true;       
}

void Corn::setCornEvent(bool cornEvent){ //setter for cornEvent

    this -> cornEvent = cornEvent;

}

bool Corn::getCornEvent(){ //getter for cornEvent

    return cornEvent;

}