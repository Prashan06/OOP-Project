#include "Pigs.h"

Pigs::Pigs() : maxPigCapacity(10), PigCount(0), PigPrice(5){}
int Pigs::setMaxAnimalCapacity(int maxPigCapacity){
    this ->maxPigCapacity = maxPigCapacity;
}

void Pigs::increaseBarnCapacity(){
    this -> maxPigCapacity = maxPigCapacity + 5;
}
int Pigs::getPigCount() {
    return PigCount;
}



