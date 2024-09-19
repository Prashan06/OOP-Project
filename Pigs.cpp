#include "Pigs.h"

Pigs::Pigs() : pigGrowthRate(30), maxPigCapacity(10), pigCount(0), pigPrice(5), increaseCapacityPrice(10), sellPrice(8), sellReadyPigCount(0), numberOfTimesPigsAreBought(0), Barn(){}

int Pigs::setMaxAnimalCapacity(int maxPigCapacity) {
    this -> maxPigCapacity = maxPigCapacity;
    std::cout << "Max Pig Capacity is: " << maxPigCapacity << std::endl; 
}

void Pigs::increaseBarnCapacity() {
    if (Money > increaseCapacityPrice) {
        cout << "would you like to increase the capacity? Enter Y or N" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }

        if (optionChoice == "Y") {
            this -> maxPigCapacity = maxPigCapacity + 5;
            this-> Money = getMoneyCount() - increaseCapacityPrice;
        }
    }
    std::cout << "Max Pig Capacity is: " << maxPigCapacity << std::endl; 

}
int Pigs::getPigCount() {
    return pigCount;
}

void Pigs::buyItem() {
    cout << "how many pigs would you like to buy, you can buy " << getMoneyCount()/pigPrice << " pigs: " << endl;
    cin >> boughtPigs;
    while (boughtPigs > getMoneyCount()/pigPrice) {
        cout << "Not enough money to buy that many pigs, please enter a number less than" << Money/pigPrice << "pigs" << endl;
    }
    pigCount = pigCount + boughtPigs;
    std::cout << "Number of pigs are: " << pigCount << std::endl;
    pigArray[numberOfTimesPigsAreBought] = boughtPigs;
    time_t boughtTime = std::time(nullptr);
    timeArray[numberOfTimesPigsAreBought] = boughtTime;
    numberOfTimesPigsAreBought++;
    Money = getMoneyCount() - (boughtPigs * pigPrice);
    std::cout << "Money is: " << getMoneyCount() << " Pig Count is:  " << getPigCount() << std::endl;
}

int Pigs::sellItem() {
    int soldIndex = 0;
    time_t currentTime = std::time(nullptr);
    for (int i = 0; i < numberOfTimesPigsAreBought; i++){
        if (difftime(currentTime, timeArray[i]) >= pigGrowthRate){
            sellReadyPigCount = sellReadyPigCount + pigArray[i];
            soldIndex++;
        }
    }

    sellReadyPigPrice = sellReadyPigCount * sellPrice;

    cout << "You can sell " << sellReadyPigCount << " pigs for " << sellReadyPigPrice << " dollars." << endl;
    cout << "Would you like to sell them? Enter Y or N" << endl; 
    cin >> optionChoice;

    while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
    }

    if (optionChoice == "Y") {
        for (int j = soldIndex; j < numberOfTimesPigsAreBought; j++) {
            pigArray[j] = pigArray[j - soldIndex];
            timeArray[j] = timeArray[j - soldIndex];
            numberOfTimesPigsAreBought = numberOfTimesPigsAreBought - soldIndex;
            pigCount = pigCount - sellReadyPigCount;
            Money = Money + sellReadyPigPrice;
        }       
    }
    std::cout << "number of times pigs are bought are: " <<numberOfTimesPigsAreBought<<" Pig Count is: " << getPigCount() << "Money is: " << getMoneyCount() << std::endl;
}


Pigs::~Pigs() {
    delete [] timeArray;
    delete [] pigArray;
}

