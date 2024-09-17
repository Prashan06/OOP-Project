#include "Pigs.h"

Pigs::Pigs() : maxPigCapacity(10), PigCount(0), PigPrice(5), increaseCapacityPrice(10) {}

int Pigs::setMaxAnimalCapacity(int maxPigCapacity){
    this -> maxPigCapacity = maxPigCapacity;
}

void Pigs::increaseBarnCapacity(){
    if (Money > increaseCapacityPrice) {
        cout << "would you like to increase the capacity? Enter Y or N" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalide input! please enter Y or N" << endl;
            cin >> optionChoice;
        }

        if (optionChoice == "Y"){
            this -> maxPigCapacity = maxPigCapacity + 5;
            Money = Money - increaseCapacityPrice;
        }
    }
}
int Pigs::getPigCount() {
    return PigCount;
}

void Pigs::buyItem() {
    cout << "how many pigs would you like to buy, you can buy" << Money/PigPrice << "Pigs" << endl;
    cin >> boughtPigs;
    while (boughtPigs > Money/PigPrice) {
        cout << "Not enough money to buy that many pigs, please enter a number less than" << Money/PigPrice << "pigs" << endl;
    }
    PigCount = PigCount + boughtPigs;
    pigArray[numberOfTimesPigsAreBought] = boughtPigs;
    timeArray[numberOfTimesPigsAreBought] = time_t(NULL) - time_t(0);
    numberOfTimesPigsAreBought++;
    Money = Money - (boughtPigs * PigPrice);

}

int Pigs::sellItem(){
    int soldIndex = 0;
    for (int i = 0; i < numberOfTimesPigsAreBought; i++){
        if (timeArray[i] >= 30){
            sellReadyPigCount = sellReadyPigCount + pigArray[i];
            soldIndex++;
        }
    }

    sellReadyPigPrice = sellReadyPigCount * sellPrice;

    cout << "You can sell " << sellReadyPigCount << " pigs " << " for " << sellReadyPigPrice << " dollars." << endl;
    cout << "Would you like to sell them? Enter Y or N" << endl; 

    while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalide input! please enter Y or N" << endl;
            cin >> optionChoice;
    }

    if (optionChoice == "Y") {
        for (int j = 0; j < numberOfTimesPigsAreBought; j++){
            pigArray[j] = pigArray[j - soldIndex];
            timeArray[j] = timeArray[j - soldIndex];
            numberOfTimesPigsAreBought = numberOfTimesPigsAreBought - soldIndex;
        }       
    }
}


