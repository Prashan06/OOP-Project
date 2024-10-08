#include <random>
#include "Cow.h"

Cow::Cow() : Barn() {
    this -> sellPrice = 10;
    this -> buyPrice = 15;
    this -> sellTime = 30;
}

void Cow::applyHighYield(int &money, int &cowCount, Cow** cow){
    if (money < highYieldPrice){
        cout << "You do not have enough money to buy high yield" << endl;
    } else {
        money = money - this-> highYieldPrice;
        cowHighYieldApplied = true;
        cout << "highYield successfully applied" << endl;
    }
}


void Cow::Event(int &count, Cow** cow, Pig** pig, Corn** corn, Wheat** wheat){
    if (count % 10 == 0) {
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 10); // define the range
        int randomNumber = distr(gen);
        if (randomNumber == 1) {
            cout << "A disease has spread throughout the cows, half of your cows have died." << endl;
            int newCowCount = count * 0.5;
            for (int i = newCowCount; i < count; i++){
                cow[i - newCowCount] = cow[i];
            }
            count = newCowCount;
        }
    }
}


Cow::~Cow(){}