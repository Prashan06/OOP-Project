#include <cstring>
#include "Farmer.h"

using namespace std;


// Constructor 
Farmer:: Farmer() : money(50), pig(nullptr), cow(nullptr), wheat(nullptr), corn(nullptr), farmName(""), pigCount(0), cowCount(0), wheatCount(0), cornCount(0), timesWheatPlanted(0), timesCornPlanted(0), timesCowsBought(0), timesPigsBought(0) {}

// sets the amount of money the farmer has.
void Farmer::setMoneyCount(int money){
    this -> money = money;
}

// Returns the amount of money the farmer has.
int Farmer::getMoneyCount(){
    return money;
}

// sets the farm name.
void Farmer::setFarmName() {
    bool validName = true;
    // if the name entered is valid, the program will continue. Otherwise the user is prompted for another entry.
    while (validName){
        cout << "What would you like to call your farm? (max 20 characters): " << endl;
        cin >> farmName;
        int i = 0;
        while (farmName[i] != '\0'){
            i++;
        }
        if (i > 20){
            cout << "Farm name is too long, please enter a shorter one." << endl;
        } else {
            validName = false;
        }
    }
}

//returns the farm name.
string Farmer::getFarmName() {
    return farmName;
}

// returns the farm name and money.
void Farmer:: getStatus(){
    std::cout << "Hello " << getFarmName() << std::endl;
    std::cout << "Your bank account holds: " << getMoneyCount() << " Dollars" << std::endl;
    std::cout << "You have " << cowCount << " cows" << std::endl;
    std::cout << "You have " << pigCount << " pigs" << std::endl;
    std::cout << "You have " << cornCount << " corns" << std::endl;
    std::cout << "You have " << wheatCount << " wheat" << std::endl;
}

void Farmer:: buyItem(){
    Cow tempCow;
    string product;
    cout << "What animal or crop would you like to buy, please choose cow, pig, wheat and corn? Enter response in lower case " << endl;
    cin >> product;
    while (product != "cow" && product != "wheat" && product != "pig" && product != "corn") {
        cout << "invalid input! please enter cow, wheat, pig or corn" << endl;
        cin >> product;
    }
    int amount = 0;

    if (strcmp(product.c_str(), "cow") == 0) {
        cout << "How many cows would you like to buy?, you can buy" << endl;
        cin >> amount;
        int amountPaid = tempCow.getBuyPrice()*amount;
        money = money - amountPaid;
        if (money < amountPaid ) {
            cout << "You do not have enough money to buy " << amount << " cows" << endl;
            money = money + tempCow.getBuyPrice()*amount;
        }
        for (int i = cowCount ; i < cowCount + amount; i++ ){
            cow[i] = tempCow.createNewCow();
            timesCowsBought++;
        }
    } else(strcmp(product.c_str(), "pig")){

    } else(strcmp(product.c_str(), "wheat")){
        
    } else(strcmp(product.c_str(), "corn")){
        
    }
    switch (product) {
        case "cow" :
            
        case "pig":
            cout << "How many pigs would you like to buy? " << endl;
            cin >> amount;
            int amountPaid = pig.getBuyPrice()*amount;
            money = money - amountPaid;
            if (money < amountPaid ) {
                cout << "You do not have enough money to buy " << amount << " pigs" << endl;
                money = money + pigs.getBuyPrice()*amount;
            }
            for (int i = pigCount ; i < pigCount + amount; i++ ){
                pig[i] = Pig* c(timesPigsBought);
                timesPigsBought++;
            }
        case "corn":
            cout << "How many corn would you like to buy? " << endl;
            cin >> amount;
            int amountPaid = corn.getBuyPrice()*amount;
            money = money - amountPaid;
            if (money < amountPaid ) {
                cout << "You do not have enough money to buy " << amount << " pigs" << endl;
                money = money + corn.getBuyPrice()*amount;
            }
            for (int i = cornCount ; i < cornCount + amount; i++ ){
                corn[i] = Corn* c(timesCornPlanted);
                timesCornPlanted++;
            }
        case "wheat": 
            cout << "How many wheat would you like to buy? " << endl;
            cin >> amount;
            int amountPaid = wheat.getBuyPrice()*amount;
            money = money - amountPaid;
            if (money < amountPaid ) {
                cout << "You do not have enough money to buy " << amount << " wheat" << endl;
                money = money + wheat.getBuyPrice()*amount;
            }
            for (int i = wheatCount ; i < wheatCount + amount; i++ ){
                wheat[i] = Wheat* c(timesWheatPlanted);
                timesWheatPlanted++;
            }
    }
}

void Farmer:: sellItem(){
        char product;
        char yesNo;
    cout << "What animal or crop would you like to sell? (Enter response in lower case)" << endl;
    cin >> product;
    switch (product) {
        case 'cow':
            int cowsReadyToSell;
            for (int i = 0, i < cowCount, i++){
                bool readyToSell = 0;
                if (cow[i].timer > timeToSell){
                    cowsReadyToSell++;
                }
            }
            cout << "You have " << cowReadyToSell << " cows ready to sell, would you like to proceed to sale (enter yes/no)? " << endl;
            cin >> yesNo;
            timesCowsBought = timesCowsBought + amount;
            int totalBuyPrice = cow.getBuyPrice()*amount;
            //money = money - total
            if (money < totalBuyPrice ) {
                cout << "You do not have enough money to buy " << amount << " cows" << endl;
            }else{
                money = money - totalBuyPrice;
            for (int i = cowCount ; i < cowCount + amount; i++ ){
                cow[i] = Cow* c(i);
                cowCount++;
            }
            }
        case 'pig': 
        case 'cow' :
                
        case 'pig':
            
        case 'corn':
        case 'wheat': 
    }
}

//Returns the combined number of wheat and corn currently in the farm.
int Farmer:: getCropCount(){
    return this -> wheatCount + this ->cornCount;
}

//Sets the combined number of wheat and corn currently in the farm.
void Farmer:: setCropCount(){
    this->cropCount = Wheat.size() + Corn.size();
}

// returns the number of pig and cows currently in the farm
int Farmer::getAnimalCount(){
    return this-> cowCount + this-> pigCount;
}

int Farmer::getCowCount(){
    return cowCount;
}

int Farmer::getPigCount(){
    return pigCount;
}

int Farmer::getWheatCount(){
    return wheatCount;
}

int Farmer:: getCornCount(){
    return cornCount;
}
