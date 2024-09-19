#include <iostream>
#include "Pigs.h"
#include "Barn.h"
#include "Farmer.h"

int main(){
    Pigs p;
    char Y = 'N';
    p.getMoneyCount();
    p.setMaxAnimalCapacity(20);
    p.increaseBarnCapacity();
    p.buyItem();
    std::cout << "Y or N" << std::endl;
    std::cin >> Y;
    if (Y == 'Y'){
        p.sellItem();
    }

    return 0;
}