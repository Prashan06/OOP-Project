#include <iostream>
#include "Wheat.h"

using namespace std;


Wheat::Wheat() : wheatGrowthRate(15), maxWheatCapacity(15), wheatCount(0), wheatPrice(3), increaseCapacityPrice(8), sellPrice(5), sellReadyWheatCount(0),numberOfTimesWheatAreBought(0), newMoney(0), Field(){}

void Wheat::setMaxCropsCapacity(int maxWheatCapacity) {
    this -> maxWheatCapacity = maxWheatCapacity;
    std::cout << "Max Wheat Capacity is: " << maxWheatCapacity << std::endl; 
}

void Wheat::increaseFieldCapacity() {
    if (Money > increaseCapacityPrice) {
        std::cout << "would you like to increase the capacity? Enter Y or N" << std::endl;
        std::cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            std::cout << "invalid input! please enter Y or N" << std::endl;
            std::cin >> optionChoice;
        }

        if (optionChoice == "Y") {
            this -> maxWheatCapacity = maxWheatCapacity + 5;
            newMoney =  getMoneyCount() - increaseCapacityPrice;
            setMoneyCount(newMoney);
        }
    }
    std::cout << "Max Wheat Capacity is: " << maxWheatCapacity << std::endl; 

}
int Wheat::getWheatCount() {
    return wheatCount;
}

void Wheat::buyItem() {
    std::cout << "how much wheat would you like to buy, you can buy " << Money/wheatPrice << " pigs: " << std::endl;
    std::cin >> boughtWheat;
    while (boughtWheat > getMoneyCount()/wheatPrice) {
        std::cout << "Not enough money to buy that many wheat, please enter a number less than " << Money/wheatPrice << " wheat" << std::endl;
        cin >> boughtWheat;
    }
    wheatCount = wheatCount + boughtWheat;
    std::cout << "Number of wheat crops: " << wheatCount << std::endl;
    wheatArray[numberOfTimesWheatAreBought] = boughtWheat;
    time_t boughtTime = std::time(nullptr);
    timeArray[numberOfTimesWheatAreBought] = boughtTime;
    numberOfTimesWheatAreBought++;
    newMoney = getMoneyCount() - (boughtWheat * wheatPrice);
    setMoneyCount(newMoney);
    std::cout << "Money is: " << Money << " Wheat Count is:  " << getWheatCount() << std::endl;
}

void Wheat::sellItem() {
    int soldIndex = 0;
    time_t currentTime = std::time(nullptr);
    for (int i = 0; i < numberOfTimesWheatAreBought; i++){
        if (difftime(currentTime, timeArray[i]) >= wheatGrowthRate){
            sellReadyWheatCount = sellReadyWheatCount + wheatArray[i];
            soldIndex++;
        }
    }

    sellReadyWheatPrice = sellReadyWheatCount * sellPrice;

    std::cout << "You can sell " << sellReadyWheatCount << " pigs for " << sellReadyWheatPrice << " dollars." << std::endl;
    std::cout << "Would you like to sell them? Enter Y or N" << std::endl; 
    std::cin >> optionChoice;

    while (optionChoice != "Y" && optionChoice != "N") {
            std::cout << "invalid input! please enter Y or N" << std::endl;
            std::cin >> optionChoice;
    }

    if (optionChoice == "Y") {
        for (int j = soldIndex; j < numberOfTimesWheatAreBought; j++) {
            wheatArray[j - soldIndex] = wheatArray[j];
            timeArray[j - soldIndex] = timeArray[j];
        }    
        numberOfTimesWheatAreBought = numberOfTimesWheatAreBought - soldIndex;
        wheatCount = wheatCount - sellReadyWheatCount;
        newMoney = getMoneyCount() + sellReadyWheatPrice;
        setMoneyCount(newMoney);   
    }
    std::cout << "number of times wheat are bought are: " <<numberOfTimesWheatAreBought<<" Wheat Count is: " << getWheatCount() << " Money is: " << getMoneyCount() << std::endl;
}


Wheat::~Wheat() {
    delete [] timeArray;
    delete [] wheatArray;
}