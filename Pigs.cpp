#include "Pigs.h"

Pigs::Pigs() : maxPigCapacity(10), PigCount(0), PigPrice(5) {}

int Pigs::setMaxAnimalCapacity(int maxPigCapacity){
    this ->maxPigCapacity = maxPigCapacity;
}

void Pigs::increaseBarnCapacity(){
    this -> maxPigCapacity = maxPigCapacity + 5;
}
int Pigs::getPigCount() {
    return PigCount;
}

<<<<<<< HEAD
void Pigs::buyPig() {
    cout << "how many pigs would you like to buy, you can buy" << Money/PigPrice << "Pigs" << endl;
    cin >> boughtPigs;
    while (boughtPigs > Money/PigPrice) {
        cout << "Not enough money to buy that many pigs, please enter a number less than" << Money/PigPrice << "pigs" << endl;
    }
    PigCount = PigCount + boughtPigs;
}
=======
int Pigs::sellItem(){
    if (sellReady = true){
        std::cout << "How many pigs do you want to sell: ";
    }
}


>>>>>>> 96c5cfce2f316782d0ffa3a328f16f7c99d0f47d

