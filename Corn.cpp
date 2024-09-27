#include "Corn.h"
#include <ctime>

using namespace std;

Corn::Corn() : cornGrowthRate(20), maxCornCapacity(10), cornCount(0), cornPrice(5), increaseCapacityPrice(10), sellPrice(12), sellReadyCornCount(0), numberOfTimesCornIsBought(0), newMoney(0), Field() {}

void Corn::setMaxCropCapacity(int maxCornCapacity) {
    if (maxCornCapacity < 10){
        cout << "Error: parameter maxCornCapacity is too small, make sure it at least larger than 10" << endl;
        
    } else {
        this -> maxCornCapacity = maxCornCapacity;
        cout << "Max corn capacity is: " << maxCornCapacity << endl;
    }
}

void Corn::increaseFieldCapacity() {
    if (Money > increaseCapacityPrice) {
        cout << "would you like to increase the capacity? Enter Y or N" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }

        if (optionChoice == "Y") {
            this -> maxCornCapacity = maxCornCapacity + 5;
            newMoney = getMoneyCount() - increaseCapacityPrice;
            setMoneyCount(newMoney);
        }
        cout << "Max corn capacity is: " << maxCornCapacity << endl;
    }
}
int Corn::getCornCount() {
    return cornCount;
}

void Corn::setCornCount(int cornCount) {
    if (cornCount > 0){
        this -> cornCount = cornCount;
    } else {
        cout << "Error: parameter is a negative value, make sure it is positive." << endl;
    }
}

void Corn::buyItem() {
    cout << "how many corn crops would you like to buy, you can buy" << Money/cornPrice << "corn crops: " << endl;
    cin >> boughtCorn;
    while (boughtCorn > getMoneyCount()/cornPrice) {
        cout << "Not enough money to buy that many corn crops, please enter a number less than " << getMoneyCount()/cornPrice << " corn crops" << endl;
        cin >> boughtCorn;
    }
    cornCount = cornCount + boughtCorn;
    cornArray[numberOfTimesCornIsBought] = boughtCorn;
    time_t boughtTime = std::time(nullptr);
    timeArray[numberOfTimesCornIsBought] = boughtTime;
    numberOfTimesCornIsBought++;
    newMoney = getMoneyCount() - (boughtCorn * cornPrice);
    setMoneyCount(newMoney);
    cout << "Money is: " << Money << " Corn count is:  " << getCornCount() << endl;

}

void Corn::sellItem() {
    int soldIndex = 0;
    time_t currentTime = std::time(nullptr);
    for (int i = 0; i < numberOfTimesCornIsBought; i++) {
        if (difftime(currentTime, timeArray[i]) >= cornGrowthRate) {
            sellReadyCornCount = sellReadyCornCount + cornArray[i];
            soldIndex++;
        }
    }

    sellReadyCornPrice = sellReadyCornCount * sellPrice;

    cout << "You can sell " << sellReadyCornCount << " corn crops " << " for " << sellReadyCornPrice << " dollars." << endl;
    cout << "Would you like to sell them? Enter Y or N" << endl; 
    cin >> optionChoice;

    while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
    }

    if (optionChoice == "Y") {
        for (int j = soldIndex; j < numberOfTimesCornIsBought; j++) {
            cornArray[j - soldIndex] = cornArray[j];
            timeArray[j - soldIndex] = timeArray[j];
        }
        numberOfTimesCornIsBought = numberOfTimesCornIsBought - soldIndex;
        cornCount = cornCount - sellReadyCornCount;
        newMoney = getMoneyCount() + sellReadyCornPrice;
        setMoneyCount(newMoney);
        
    }
    cout << "Corn crop count is: " << getCornCount() << " Money is: " << getMoneyCount() << endl;
}

int Corn::getNumberOfTimesCornIsBought() {
    return numberOfTimesCornIsBought;
}

void Corn::setNumberOfTimesCornIsBought(int numberOfTimesCornIsBought) {
    this -> numberOfTimesCornIsBought = numberOfTimesCornIsBought;
}

int* Corn::getTimeArray() {
    return timeArray;
}

int* Corn::getCornArray() {
    return cornArray;
}

Corn::~Corn() {
    delete [] timeArray;
    delete [] cornArray;
}