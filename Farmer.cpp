#include "Farmer.h"

using namespace std;


// Constructor 
Farmer::Farmer() : money(50), pig(new Pig*[pigCount]), cow(new Cow*[cowCount]), wheat(new Wheat*[wheatCount]), corn(new Corn*[cornCount]), farmName(""), pigCount(0), cowCount(0), wheatCount(0), cornCount(0), timesWheatPlanted(0), timesCornPlanted(0), timesCowsBought(0), timesPigsBought(0) {}

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
    Cow* newCow = new Cow;
    return newCow;
}

Pig* Farmer::createNewPig() {
    Pig* newPig = new Pig;
    return newPig;
}

Wheat* Farmer::createNewWheat() {
    Wheat* newWheat = new Wheat;
    return newWheat;
}

Corn* Farmer::createNewCorn() {
    Corn* newCorn = new Corn;
    return newCorn;
}

void Farmer::buyAnimal(){
    string product;
    cout << "What animal would you like to buy? please enter cow or pig" << endl;
    cin >> product;
    while (product != "cow" && product != "wheat" && product != "pig" && product != "corn") {
        cout << "invalid input! please enter cow or pig" << endl;
        cin >> product;
    }
    int amount = 0;

    if (product == "cow") {
        Cow tempCow;
        cout << "How many cows would you like to buy?, you can buy " << money/tempCow.getBuyPrice() << " cows" << endl;
        cin >> amount;
        int amountPaid = tempCow.getBuyPrice() * amount;
        while (money < amountPaid ) {
            cout << "You do not have enough money to buy " << amount << " cows" << endl;
            cout << "enter a new amount: ";
            cin >> amount;
        }
        money = money - amountPaid;

        for (int i = cowCount ; i < cowCount + amount; i++ ) {
            cow[i] = createNewCow();
            timesCowsBought++;
        }
        cowCount = cowCount + amount;
    } else if(product == "pig") {
        Pig tempPig;
        cout << "How many pigs would you like to buy?, you can buy " << money/tempPig.getBuyPrice() << " pigs" << endl;
        cin >> amount;
        int amountPaid = tempPig.getBuyPrice() * amount;
        while (money < amountPaid ) {
            cout << "You do not have enough money to buy " << amount << " pigs" << endl;
            cout << "enter a new amount: ";
            cin >> amount;
        }
        money = money - amountPaid;

        for (int i = pigCount ; i < pigCount + amount; i++ ) {
            pig[i] = createNewPig();
            timesPigsBought++;
        }
        pigCount = pigCount + amount;
    }
}

void Farmer:: sellAnimal(){
    string product;
    string yesNo;
    cout << "What animal would you like to sell, cow or pig? (Enter response in lower case)" << endl;
    cin >> product;
    while (product != "cow" && product != "pig") {
        cout << "invalid input! please enter cow or pig" << endl;
        cin >> product;
    }
    if (product == "cow") {
        Cow tempCow;
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
                cow[j-cowsReadyToSell] = cow[j];
                delete cow[j]; 
            }
            cowCount = cowCount - cowsReadyToSell;
            money = money + ((tempCow.getSellPrice())*cowsReadyToSell);
        }

    } else if (product == "pig") {
        Pig tempPig;
        int pigsReadyToSell;
        for (int i = 0; i < pigCount; i++){
            if (pig[i]->getTimer() > pig[i]->getSellTime()){
                pigsReadyToSell++;
            }
        }
        cout << "You have " << pigsReadyToSell << " pigs ready to sell, would you like to sell these pigs (enter yes/no)? " << endl;
        cin >> yesNo;
        while (yesNo != "yes" && yesNo != "no") {
            cout << "invalid input! please enter yes or no" << endl;
            cin >> yesNo;
        }
        if (yesNo == "yes"){
            for(int j = pigsReadyToSell; j < pigCount; j++) {
                pig[j-pigsReadyToSell] = pig[j];
                delete pig[j]; 
            }
            pigCount = pigCount - pigsReadyToSell;
            money = money + ((tempPig.getSellPrice())*pigsReadyToSell);
        }
    }   
}

void Farmer::buyCrop() {
    string product;
    cout << "What crop would you like to buy? enter wheat or corn" << endl;
    cin >> product;
    while (product != "wheat" && product != "corn") {
        cout << "invalid input! please enter wheat or corn" << endl;
        cin >> product;
    }
    int amount = 0;

    if (product == "wheat") {
        Wheat tempWheat;
        cout << "How many wheat crops would you like to buy?, you can buy " << money/tempWheat.getBuyPrice() << " wheat" << endl;
        cin >> amount;
        int amountPaid = tempWheat.getBuyPrice() * amount;
        while (money < amountPaid ) {
            cout << "You do not have enough money to buy " << amount << " wheat" << endl;
            cout << "enter a new amount: ";
            cin >> amount;
        }
        money = money - amountPaid;

        for (int i = wheatCount ; i < wheatCount + amount; i++ ) {
            wheat[i] = createNewWheat();
            timesWheatPlanted++;
        }
        wheatCount = wheatCount + amount;
    } else if (product == "corn"){
        Corn tempCorn;
        cout << "How many corn crops would you like to buy?, you can buy " << money/tempCorn.getBuyPrice() << " corn" << endl;
        cin >> amount;
        int amountPaid = tempCorn.getBuyPrice() * amount;
        while (money < amountPaid ) {
            cout << "You do not have enough money to buy " << amount << " corn" << endl;
            cout << "enter a new amount: ";
            cin >> amount;
        }
        money = money - amountPaid;

        for (int i = cornCount ; i < cornCount + amount; i++ ) {
            corn[i] = createNewCorn();
            timesCornPlanted++;
        }
        cornCount = cornCount + amount;
    }
}

void Farmer::sellCrop(){
    string product;
    string yesNo;
    cout << "What crop would you like to sell, wheat or corn? (Enter response in lower case)" << endl;
    cin >> product;
    while (product != "wheat" && product != "corn") {
        cout << "invalid input! please enter wheat or corn" << endl;
        cin >> product;
    }

    if (product == "wheat"){
        Wheat tempWheat;
        int wheatsReadyToSell;
        for (int i = 0; i < wheatCount; i++){
            if (wheat[i]->getTimer() > wheat[i]->getSellTime()){
                wheatsReadyToSell++;
            }
        }
        cout << "You have " << wheatsReadyToSell << " wheat crops ready to sell, would you like to sell these crops (enter yes/no)? " << endl;
        cin >> yesNo;
        while (yesNo != "yes" && yesNo != "no") {
            cout << "invalid input! please enter yes or no" << endl;
            cin >> yesNo;
        }
        if (yesNo == "yes"){
            for(int j = wheatsReadyToSell; j < wheatCount; j++) {
                wheat[j-wheatsReadyToSell] = wheat[j];
                delete wheat[j]; 
            }
            wheatCount = wheatCount - wheatsReadyToSell;
            money = money + ((tempWheat.getSellPrice())*wheatsReadyToSell);
        }
        
    } else if (product == "corn"){
        Corn tempCorn;
        int cornsReadyToSell;
        for (int i = 0; i < cornCount; i++){
            if (corn[i]->getTimer() > corn[i]->getSellTime()){
                cornsReadyToSell++;
            }
        }
        cout << "You have " << cornsReadyToSell << " corn crops ready to sell, would you like to sell these crops (enter yes/no)? " << endl;
        cin >> yesNo;
        while (yesNo != "yes" && yesNo != "no") {
            cout << "invalid input! please enter yes or no" << endl;
            cin >> yesNo;
        }
        if (yesNo == "yes"){
            for(int j = cornsReadyToSell; j < cornCount; j++) {
                corn[j-cornsReadyToSell] = corn[j];
                delete corn[j]; 
            }
            cornCount = cornCount - cornsReadyToSell;
            money = money + ((tempCorn.getSellPrice())*cornsReadyToSell);
        }
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

int Farmer::getCornCount(){
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
