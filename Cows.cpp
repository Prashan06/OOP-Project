#include "Cows.h"
#include <ctime>

using namespace std;

Cows::Cows() : cowGrowthRate(40), maxCowCapacity(10), cowCount(0), cowPrice(10), increaseCapacityPrice(15), sellPrice(12), sellReadyCowCount(0), numberOfTimesCowsAreBought(0), newMoney(0), Barn() {}

void Cows::setMaxAnimalCapacity(int maxCowCapacity) {
    if (maxCowCapacity < 10){
        cout << "Error: parameter maxCowCapacity is too small, make sure it at least larger than 10" << endl;
        
    } else {
        this -> maxCowCapacity = maxCowCapacity;
        cout << "Max cow capacity is: " << maxCowCapacity << endl;
    }
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
            setMaxAnimalCapacity((maxCowCapacity + 5));
            newMoney = getMoneyCount() - increaseCapacityPrice;
            setMoneyCount(newMoney);
        }
    }
}

void Cows::setCowCount(int cowCount) {
    if (cowCount > 0){
        this -> cowCount = cowCount;
    } else {
        cout << "Error: parameter is a negative value, make sure it is positive." << endl;
    }
}

int Cows::getCowCount() {
    return cowCount;
}

void Cows::buyItem() {
    cout << "how many cows would you like to buy, you can buy " << getMoneyCount()/cowPrice << " cows: " << endl;
    cin >> boughtCows;
    while (boughtCows > getMoneyCount()/cowPrice) {
        cout << "Not enough money to buy that many cows, please enter a number less than " << getMoneyCount()/cowPrice << " cows" << endl;
        cin >> boughtCows;
    }
    cowCount = cowCount + boughtCows;
    cowArray[numberOfTimesCowsAreBought] = boughtCows;
    time_t boughtTime = std::time(0);
    timeArray[numberOfTimesCowsAreBought] = boughtTime;
    numberOfTimesCowsAreBought++;
    newMoney = getMoneyCount() - (boughtCows * cowPrice);
    setMoneyCount(newMoney);
    std::cout << "Money is: " << Money << " Cow count is: " << getCowCount() << std::endl;

}

void Cows::sellItem() {
    int soldIndex = 0;
    time_t currentTime = std::time(0);
    for (int i = 0; i < numberOfTimesCowsAreBought; i++) {
        int timeDifference = difftime(currentTime, timeArray[i]);
        if (timeDifference >= cowGrowthRate) {
            sellReadyCowCount = sellReadyCowCount + cowArray[i];
            soldIndex++;
        }
    }

    sellReadyCowPrice = sellReadyCowCount * sellPrice;

    cout << "You can sell " << sellReadyCowCount << " cows" << " for " << sellReadyCowPrice << " dollars." << endl;
    cout << "Would you like to sell them? Enter Y or N" << endl; 
    cin >> optionChoice;

    while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
    }

    if (optionChoice == "Y") {
        for (int j = soldIndex; j < numberOfTimesCowsAreBought; j++) {
            cowArray[j - soldIndex] = cowArray[j];
            timeArray[j - soldIndex] = timeArray[j];
        }  
        numberOfTimesCowsAreBought = numberOfTimesCowsAreBought - soldIndex;
        cowCount = cowCount - sellReadyCowCount;
        newMoney = getMoneyCount() + sellReadyCowPrice;
        setMoneyCount(newMoney);
    }
    std::cout << "Cow Count is: " << getCowCount() << " Money is: " << getMoneyCount() << std::endl;
}

int Cows::getNumberOfTimesCowsAreBought() {
    return numberOfTimesCowsAreBought;
}

void Cows::setNumberOfTimesCowsAreBought(int numberOfTimesCowsAreBought) {
    this -> numberOfTimesCowsAreBought = numberOfTimesCowsAreBought;
}

int* Cows::getTimeArray() {
    return timeArray;
}

int* Cows::getCowArray() {
    return cowArray;
}


Cows::~Cows() {
    delete [] timeArray;
    delete [] cowArray;
}