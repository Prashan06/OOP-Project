#include <random>
#include "Pig.h"

Pig::Pig() : Barn() {
    this -> sellPrice = 10;
    this -> buyPrice = 15;
    this -> sellTime = 30;
}

void Pig::applyHighYield( int &money, int &pigCount, Pig** pig){
    if (money < highYieldPrice){
        cout << "You do not have enough money to buy high yield fertilizer" << endl;
    } else {
        money = money - this-> highYieldPrice;
        pigHighYieldApplied = true;
        cout << "highYield successfully applied" << endl;
    }
}

void Pig::Event(int &count, Cow** cow, Pig** pig, Corn** corn, Wheat** wheat){
    if (count % 10 == 0) {
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 10); // define the range
        int randomNumber = distr(gen);
        if (randomNumber == 1) {
            cout << "the demand for pig meat greatly decreased, in order to maintain a healthy flow of pigs " << endl;
            cout << "coming in and out of the farm, the sell price of all currently owned pigs must be reduced by half." << endl;
            int newPigCount = count * 0.5;
            for (int i = 0; i < count; i++){
                pig[i]->sellPrice == (pig[i]->getSellPrice()) * 0.5;
            }
            count = newPigCount;
        }
    }
}

Pig::~Pig(){}