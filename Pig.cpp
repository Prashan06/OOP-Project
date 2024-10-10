#include <random>
#include "Pig.h"

Pig::Pig() : Barn() {
    this -> sellPrice = 15;
    this -> buyPrice = 12;
    this -> sellTime = 12;
    this->highYieldPrice = 15;
}

void Pig::applyHighYield(int *money){
    if (*money < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    } else {
        *money = *money - this-> highYieldPrice;
        pigHighYieldApplied = true;
        cout << "highYield successfully applied" << endl;
    }
}

void Pig::Event(int* count){
    if (*count % 10 == 0) {
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 10); // define the range
        int randomNumber = distr(gen);
        if (randomNumber == 1) {
            pigEvent = true;
        }
    }
}

void Pig::setPigEvent(bool pigEvent) {
    this -> pigEvent = pigEvent;
}
bool Pig::getPigEvent() {
    return pigEvent;
}