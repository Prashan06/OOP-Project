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

void Pigs::buyPig() {
    cout << "how many pigs would you like to buy, you can buy" << Money/PigPrice << "Pigs" << endl;
    cin >> boughtPigs;
    while (boughtPigs > Money/PigPrice) {
        cout << "Not enough money to buy that many pigs, please enter a number less than" << Money/PigPrice << "pigs" << endl;
    }
    PigCount = PigCount + boughtPigs;
    pigArray[numberOfTimesPigsAreBought] = boughtPigs;
    timeArray[numberOfTimesPigsAreBought] = time_t(NULL) - time_t(0);
    numberOfTimesPigsAreBought++;
    Money = Money - (boughtPigs * PigPrice);

}

int Pigs::sellItem(){
    if (sellReady = true){
        std::cout << "How many pigs do you want to sell: " << 
    }
}



