#include <iostream>
#include "Barn.h"
#include "Farm.h"
#include "Farmer.h"

using namespace std;

Barn::Barn() : Farmer(), animalCount(0) {}

void Barn::setAnimalCount(int pigCount, int cowCount) {
    this -> animalCount = pigCount + cowCount; 
}

int Barn::getAnimalCount() {
    return animalCount;
}

int Barn::setMaxAnimalCapacity(){}
void Barn::increaseBarnCapacity(){}

void Barn::sellItem() {}
void Barn::buyItem() {}
