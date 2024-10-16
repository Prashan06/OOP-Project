#include "Pig.h"

#include <random>

Pig::Pig() : Barn() {  // constructor
  this->sellPrice = 15;
  this->buyPrice = 12;
  this->sellTime = 12;
  this->highYieldPrice = 15;
}

// This functions sets the pigHighYieldApplied to true. The code to increase the
// price of pig objects is in Farmer
void Pig::applyHighYield(int* money) {
  // Decreases the money and sets cowHighYieldApplied to true.
  *money = *money - this->highYieldPrice;
  pigHighYieldApplied = true;
}

// This functions sets pigEvent to true depending on the value of pigCount. The
// code to affect the pig is in Farmer
void Pig::Event(int* count) {
  if (*count % 5 == 0) {
    random_device rd;   // obtain a random number from hardware
    mt19937 gen(rd());  // seed the generator, initialise generator
    uniform_int_distribution<> distr(1, 20);  // define the range
    int randomNumber = distr(gen);
    if (randomNumber == 1) {
      this->pigEvent = true;
      setPigEvent(pigEvent);
    }
  }
}

void Pig::setPigEvent(bool pigEvent) {  // setter for pigEvent
  this->pigEvent = pigEvent;
}

bool Pig::getPigEvent() {  // getter for pigEvent
  return pigEvent;
}