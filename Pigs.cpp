#include "Pigs.h"

Pigs::Pigs() : maxPigCapacity(10), PigCount(0), PigPrice(5), increaseCapacityPrice(10) {}

int Pigs::setMaxAnimalCapacity(int maxPigCapacity){
    this -> maxPigCapacity = maxPigCapacity;
}

void Pigs::increaseBarnCapacity(){
    if (Money > increaseCapacityPrice) {
        cout << "would you like to increase the capacity? Enter Y or N" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" || optionChoice != "N") {
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
<<<<<<< HEAD
    if (sellReady = true){
        std::cout << "How many pigs do you want to sell: " << endl;
=======
    for (int i  = 0; i < numberOfTimesPigsAreBought; i++){
        if (sellReady == true){
            sellReadyPigCount = sellReadyPigCount + pigArray[i];
        }
    }

    sellReadyPigPrice = sellReadyPigCount * sellPrice;

    std::cout << "You can sell " << sellReadyPigCount << " pigs " << " for " << sellReadyPigCount * sellPrice << " dollars." << std::endl; 

    if (optionchoice == "Y") {
        int index = 0;
        for (index = 0; index < numberOfTimesPigsAreBought; index++){
            if (sellReady == true){
                pigArray[index] = 0;
                timeArray[index] = 0;
                soldPigsCount++;
            }
        }
        
        for (int j = index; index < numberOfTimesPigsAreBought; j ++){
            pigArray[j] = pigArray[j+soldPigsCount];
            timeArray[j] = timeArray[i+soldPigsCount];
        } 
>>>>>>> 10beadfc9ffc7afd37a276b5cb6166d801f7638f
    }
}


