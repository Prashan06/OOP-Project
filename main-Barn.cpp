#include <iostream>
#include "Pigs.h"
#include "Barn.h"
#include "Farmer.h"

int main(){
    Pigs p;

    p.setMaxAnimalCapacity(20);
    p.increaseBarnCapacity();
    p.buyItem();
    p.sellItem();

    return 0;
}