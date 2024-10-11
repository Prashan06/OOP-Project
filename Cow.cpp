#include <random>
#include "Cow.h"

Cow::Cow() : Barn(){ //constructor

    this -> sellPrice = 18;
    this -> buyPrice = 15;
    this -> sellTime = 15;

}

void Cow::applyHighYield(int* money){

    if (*money < highYieldPrice){

        cout << "You do not have enough money to buy high yield" << endl; // checks whether the player has enough money to execute the function

    } else{
        // Decreases the money and sets cowHighYieldApplied to true.
        *money = (*money) - this-> highYieldPrice;
        cowHighYieldApplied = true;
        cout << "highYield successfully applied" << endl;

    }

}


void Cow::Event(int* count){

    if (*count % 10 == 0){

        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 10); // define the range
        int randomNumber = distr(gen);

        if (randomNumber == 1){

            cowEvent == true;

        }

    }

}

void Cow::setCowEvent(bool cowEvent){ //setter for cowEvent
    this -> cowEvent = cowEvent;
}

bool Cow::getCowEvent(){ //getter for cowEvent
    return cowEvent;
}