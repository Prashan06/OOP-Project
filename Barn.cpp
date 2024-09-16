#include <iostream>
#include "Barn.h"
#include "Farm.h"

using namespace std;

Barn::Barn() : animalCount(0), breedPrice(0) {}

void Barn::breedAnimals(){
    if (animalCount % 2 == 0){
        animalCount = animalCount + animalCount*0.5;
    } else {
        animalCount = animalCount + (animalCount - 1)*0.5;
    }
}

void Barn::setPrice() {
    breedPrice = 80;
}

