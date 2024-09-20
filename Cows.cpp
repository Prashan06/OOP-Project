#include "Cows.h"
#include <ctime>

using namespace std;

Cows::Cows() : cowGrowthRate(40), maxCowCapacity(10), cowCount(0), cowPrice(10), increaseCapacityPrice(15), sellPrice(12), sellReadyCowCount(0), numberOfTimesCowsAreBought(0), newMoney(0), Barn() {}

int Cows::setMaxAnimalCapacity(int maxCowCapacity) {
    this -> maxCowCapacity = maxCowCapacity;
    cout << "Max cow capacity is: " << maxCowCapacity << endl;
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
            newMoney = getMoneyCount() - increaseCapacityPrice;
            setMoneyCount(newMoney);
        }
        cout << "Max cow capacity is: " << maxCowCapacity << endl;
    }
}
int Cows::getCowCount() {
    return cowCount;
}

void Cows::buyItem() {
    cout << "how many cows would you like to buy, you can buy" << Money/cowPrice << "cows: " << endl;
    cin >> boughtCows;
    while (boughtCows > getMoneyCount()/cowPrice) {
        cout << "Not enough money to buy that many cows, please enter a number less than" << getMoneyCount()/cowPrice << "cows" << endl;
    }
    cowCount = cowCount + boughtCows;
    cowArray[numberOfTimesCowsAreBought] = boughtCows;
    time_t boughtTime = std::time(nullptr);
    timeArray[numberOfTimesCowsAreBought] = boughtTime;
    numberOfTimesCowsAreBought++;
    newMoney = getMoneyCount() - (boughtCows * cowPrice);
    setMoneyCount(newMoney);
    std::cout << "Money is: " << Money << " Cow count is:  " << getCowCount() << std::endl;

}

void Cows::sellItem() {
    int soldIndex = 0;
    time_t currentTime = std::time(nullptr);
    for (int i = 0; i < numberOfTimesCowsAreBought; i++) {
        if (difftime(currentTime, timeArray[i]) >= cowGrowthRate) {
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
        for (int j = soldIndex; j < numberOfTimesCowsAreBought; j++) {
            cowArray[j] = cowArray[j - soldIndex];
            timeArray[j] = timeArray[j - soldIndex];
            numberOfTimesCowsAreBought = numberOfTimesCowsAreBought - soldIndex;
            cowCount = cowCount - sellReadyCowCount;
        }  
        newMoney = getMoneyCount() + sellReadyCowPrice;
        setMoneyCount(newMoney);
    }
    std::cout <<" Cow Count is: " << getCowCount() << " Money is: " << getMoneyCount() << std::endl;
}

Cows::~Cows() {
    delete [] timeArray;
    delete [] cowArray;
}