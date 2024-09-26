#include <iostream>
#include "Barn.h"
#include "Farm.h"
#include "Farmer.h"

using namespace std;

Barn::Barn() : Farmer(), animalCount(0) {}

void Barn::setAnimalCount(int pigCount, int cowCount) {
    if (pigCount >= 0 && cowCount >= 0){
        this -> animalCount = pigCount + cowCount; 
    }
    else {
        cout << "error: one or both of the parameters of setAnimalCount is negative, make sure they are both positive" << endl;
    }
}

int Barn::getAnimalCount() {
    return animalCount;
}

int Barn::setMaxAnimalCapacity(){
    return 0;
}
void Barn::increaseBarnCapacity(){}

void Barn::sellItem() {}
void Barn::buyItem() {}
