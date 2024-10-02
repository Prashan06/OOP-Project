#include "Farmer.h"

// Constructor 
Farmer:: Farmer() : money(50),pig(0),cow(0),wheat(0),corn(0),farmName(""),cropCount(0),animalCount(0){}

// sets the amount of money the farmer has.
void Farmer:: setMoney(int money){
    this -> money = money;
}

// Returns the amount of money the farmer has.
int Farmer:: getMoney(){
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
    std::cout << "Your bank account holds: " << getMoney() << " Dollars" << std::endl;
    std::cout << "You have " << cowCount << " cows" << std::endl;
    std::cout << "You have " << pigCount << " pigs" << std::endl;
    std::cout << "You have " << cornCount << " corns" << std::endl;
    std::cout << "You have " << wheatCount << " wheat" << std::endl;
}

void Farmer:: buyItem(){
    char product;
    cout << "What animal or crop would you like to buy? Enter response in lower case " << endl;
    cin >> product;
    int amount = 0;
    switch (product) {
        case 'cow' :
            cout << "How many cows would you like to buy? " << endl;
            cin >> amount;
            int amountPaid = cow.getBuyPrice()*amount;
            money = money - amountPaid;
            if (money < amountPaid ) {
                cout << "You do not have enough money to buy " << amount << " cows" << endl;
                money = money + cow.getBuyPrice()*amount;
            }
            for (int i = cowCount ; i < cowCount + amount; i++ ){
                cow[i] = Cow* c(timesCowsBought);
                timesCowsBought++;
            }
        case 'pig':
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
        case 'corn':
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
        case 'wheat': 
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
    cout << "What animal or crop would you like to sell? Enter response in lower case " << endl;
    cin >> product;
    int amount = 0;
    switch (product) {
        case 'cow' :
            cout << "How many cows would you like to buy? " << endl;
            cin >> amount;
            timesCowsBought = timesCowsBought + amount;
            money = money - cow.getBuyPrice()*amount;
            if (money < 0 ) {
                cout << "You do not have enough money to buy " << amount << " cows" << endl;
                money = money + cow.getBuyPrice()*amount;
            }
            for (int i = cowCount ; i < cowCount + amount; i++ ){
                cow[i] = Cow* c(i);
                cowCount++;
            }
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
