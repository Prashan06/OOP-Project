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

Cow* Farmer::createNewCow() {
    Cow* newCow;
    return newCow;
}

Pig* Farmer::createNewPig() {
    Pig* newPig;
    return newPig;
}

Wheat* Farmer::createNewWheat() {
    Wheat* newWheat;
    return newWheat;
}

Corn* Farmer::createNewCorn() {
    Corn* newCorn;
    return newCorn;
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

    if (product == "cow") {
        cout << "How many cows would you like to buy?, you can buy " << money/tempCow.getBuyPrice() << " cows" << endl;
        cin >> amount;
        int amountPaid = tempCow.getBuyPrice()*amount;
        money = money - amountPaid;
        if (money < amountPaid ) {
            cout << "You do not have enough money to buy " << amount << " cows" << endl;
            money = money + tempCow.getBuyPrice()*amount;
        }

        for (int i = cowCount ; i < cowCount + amount; i++ ) {
            cow[i] = createNewCow();
            timesCowsBought++;
        }
    } else if(product == "pig") {

    } else if (product == "wheat"){
        
    } else if (product == "corn"){
        
    }
    
}

void Farmer:: sellItem(){
    Cow tempCow;
    string product;
    string yesNo;
    cout << "What animal or crop would you like to sell, cow, pig, wheat and corn? (Enter response in lower case)" << endl;
    cin >> product;
    while (product != "cow" && product != "wheat" && product != "pig" && product != "corn") {
        cout << "invalid input! please enter cow, wheat, pig or corn" << endl;
        cin >> product;
    }
    if (product == "cow") {
        int cowsReadyToSell;
        for (int i = 0; i < cowCount; i++){
            if (cow[i]->getTimer() > cow[i]->getSellTime()){
                cowsReadyToSell++;
            }
        }
        cout << "You have " << cowsReadyToSell << " cows ready to sell, would you like to sell these cows (enter yes/no)? " << endl;
        cin >> yesNo;
        while (yesNo != "yes" && yesNo != "no") {
            cout << "invalid input! please enter yes or no" << endl;
            cin >> yesNo;
        }
        if (yesNo == "yes"){
            for(int j = cowsReadyToSell; j < cowCount; j++) {
                cow[i]
            }
        }
    }
    switch (product) {
        case 'cow':
  
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


void Farmer::setCowCount(int cowCount){
    this->cowCount = cowCount;
}

void Farmer::setPigCount(int pigCount){
    this->pigCount = pigCount;
}

void Farmer::setWheatCount(int wheatCount){
    this->wheatCount = wheatCount;
}

void Farmer::setCornCount(int cornCount){
    this->cornCount = cornCount;
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

Cow** Farmer::getCowArray() {
    return cow;
}
Pig** Farmer::getPigArray() {
    return pig;
}
Wheat** Farmer::getWheatArray() {
    return wheat;
}
Corn** Farmer::getCornArray() {
    return corn;
}
