#include <iostream>
#include "Barn.h"
#include "Farm.h"

using namespace std;

Barn::Barn() : Farmer(), animalCount(0) {}

void Barn::setAnimalCount(int pigCount, int cowCount) {
    animalCount = pigCount + cowCount; 
}

int Barn::getAnimalCount() {
    return animalCount;
}

