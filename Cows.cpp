#include "Cows.h"

Cows::Cows() : cowGrowthRate(40), maxCowCapacity(10), cowCount(0), cowPrice(10), increaseCapacityPrice(15) {}

int Cows::setMaxAnimalCapacity(int maxCowCapacity) {
    this -> maxCowCapacity = maxCowCapacity;
}

void Cows::increaseBarnCapacity() {
    if (Money > increaseCapacityPrice) {
        cout << "would you like to increase the capacity? Enter Y or N" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }

        if (optionChoice == "Y") {
            this -> maxCowCapacity = maxCowCapacity + 5;
            Money = Money - increaseCapacityPrice;
        }
    }
}
int Cows::getCowCount() {
    return cowCount;
}

void Cows::buyItem() {
    cout << "how many pigs would you like to buy, you can buy" << Money/cowPrice << "cows: " << endl;
    cin >> boughtCows;
    while (boughtCows > Money/cowPrice) {
        cout << "Not enough money to buy that many cows, please enter a number less than" << Money/cowPrice << "cows" << endl;
    }
    cowCount = cowCount + boughtCows;
    cowArray[numberOfTimesCowsAreBought] = boughtCows;
    timeArray[numberOfTimesCowsAreBought] = time_t(NULL) - time_t(0);
    numberOfTimesCowsAreBought++;
    Money = Money - (boughtCows * cowPrice);

}

int Cows::sellItem() {
    int soldIndex = 0;
    for (int i = 0; i < numberOfTimesCowsAreBought; i++) {
        if (timeArray[i] >= cowGrowthRate) {
            sellReadyCowCount = sellReadyCowCount + cowArray[i];
            soldIndex++;
        }
    }

    sellReadyCowPrice = sellReadyCowCount * sellPrice;

    cout << "You can sell " << sellReadyCowCount << " cows " << " for " << sellReadyCowPrice << " dollars." << endl;
    cout << "Would you like to sell them? Enter Y or N" << endl; 

    while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
    }

    if (optionChoice == "Y") {
        for (int j = 0; j < numberOfTimesCowsAreBought; j++) {
            cowArray[j] = cowArray[j - soldIndex];
            timeArray[j] = timeArray[j - soldIndex];
            numberOfTimesCowsAreBought = numberOfTimesCowsAreBought - soldIndex;
            cowCount = cowCount - sellReadyCowCount;
        }       
    }
}