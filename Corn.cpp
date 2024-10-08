#include <random>
#include "Corn.h"


Corn::Corn():Field(){
    this->buyPrice = 20;
    this->sellPrice = 30;
    this->sellTime = 5;
    this->highYieldPrice = 10;

}

void Corn::Event(int* count){
    if (*count % 10 == 0) {
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 10); // define the range
        int randomNumber = distr(gen);

        if (randomNumber == 1) {
            cornEvent = true;
        }
    }
}

void Corn::applyHighYield(int* money){

    if (*money < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    } else {
        *money = (*money) - this->highYieldPrice;
        cornHighYieldApplied = true;
        cout << "highYield successfully applied" << endl;
    }

}

void Corn::setCornEvent(bool cornEvent) {
    this -> cornEvent = cornEvent;
}
bool Corn::getCornEvent() {
    return cornEvent;
}