#include "Farmer.h"

using namespace std;


// Constructor 
Farmer::Farmer() : money(50), pig(new Pig*[pigCount]), cow(new Cow*[cowCount]), wheat(new Wheat*[wheatCount]), corn(new Corn*[cornCount]), farmName(""), timesWheatPlanted(0), timesCornPlanted(0), timesCowsBought(0), timesPigsBought(0) {}

// sets the amount of money the farmer has.
void Farmer::setMoneyCount(int money){
    this -> money = money;
}

// Returns the amount of money the farmer has.
int* Farmer::getMoneyCount(){
    return &money;
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
    std::cout << "Your bank account holds: " << *getMoneyCount() << " Dollars" << std::endl;
    std::cout << "You have " << cowCount << " cows" << std::endl;
    std::cout << "You have " << pigCount << " pigs" << std::endl;
    std::cout << "You have " << cornCount << " corns" << std::endl;
    std::cout << "You have " << wheatCount << " wheat" << std::endl;
}

Cow* Farmer::createNewCow() {
    Cow* newCow = new Cow;
    return new Cow;
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
        for (int i = cowCount ; i < (cowCount + amount); i++ ) {
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
        int cowsReadyToSell = 0;
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
        int pigsReadyToSell = 0;
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
        int wheatsReadyToSell = 0;
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
        int cornsReadyToSell = 0;
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

int* Farmer::getCowCount(){
    return &cowCount;
}

int* Farmer::getPigCount(){
    return &pigCount;
}

int* Farmer::getWheatCount(){
    return &wheatCount;
}

int* Farmer::getCornCount(){
    return &cornCount;
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

void Farmer::speedGrowthBought() {
    if (cow[0]->getBarnSpeedGrowthApplied() == true) {
        for (int i = 0; i < *getCowCount() ; i++) {
            cow[i]->setSellTime((cow[i]->getSellTime())-1);
            cow[i]->setBarnSpeedGrowthApplied(false);
        }
        for (int i = 0; i < *getPigCount() ; i++) {
            pig[i]->setSellTime((pig[i]->getSellTime())-1);
            pig[i]->setBarnSpeedGrowthApplied(false);
        }
    } else if (corn[0]->getFieldSpeedGrowthApplied() == true) {
        for (int i = 0; i < *getCornCount() ; i++) {
            corn[i]->setSellTime((corn[i]->getSellTime())-1);
            corn[i]->setBarnSpeedGrowthApplied(false);
        }
        for (int i = 0; i < *getWheatCount() ; i++) {
            wheat[i]->setSellTime((wheat[i]->getSellTime())-1);
            wheat[i]->setBarnSpeedGrowthApplied(false);
        }
    }
}

void Farmer::highYieldBought() {
    if (cow[0]->getCowHighYieldApplied() == true) {
        for (int i = 0; i < cowCount ; i++) {
            cow[i]->setSellPrice(cow[i]->getSellPrice() * cow[i]->getHighYieldFactor());
            cow[i]->setCowHighYieldApplied(false);
        }
    } else if (pig[0]->getPigHighYieldApplied() == true) {
        for (int i = 0; i < pigCount ; i++) {
            pig[i]->setSellPrice(pig[i]->getSellPrice() * pig[i]->getHighYieldFactor());
            pig[i]->setPigHighYieldApplied(false);
        }
    } else if (wheat[0]->getWheatHighYieldApplied() == true) {
        for (int i = 0; i < wheatCount; i++){
            wheat[i]->setSellPrice(wheat[i]->getSellPrice() * wheat[i]->getHighYieldFactor());
            wheat[i]->setWheatHighYieldApplied(false);
        }
    } else if (corn[0]->getCornHighYieldApplied() == true) {
        for (int i = 0; i < cornCount ; i++) {
            corn[i]->setSellPrice(corn[i]->getSellPrice() * corn[i]->getHighYieldFactor());
            corn[i]->setCornHighYieldApplied(false);
        }
    }
}

void Farmer::executeEvent() {
    if (getCowEvent() == true) {
        cout << "A disease has spread throughout the cows, half of your cows have died." << endl;
            int newCowCount = cowCount * 0.5;
            for (int i = newCowCount; i < cowCount; i++){
                cow[i - newCowCount] = cow[i];
                cow[i]->setCowEvent(false);
            }
        cowCount = newCowCount;
    } else if (getPigEvent() == true) {
        cout << "the demand for pig meat greatly decreased, in order to maintain a healthy flow of pigs " << endl;
        cout << "coming in and out of the farm, the sell price of all currently owned pigs must be reduced by half." << endl;
        int newPigCount = (pigCount) * 0.5;
        for (int i = 0; i < pigCount; i++){
            pig[i]->setSellPrice((pig[i]->getSellPrice()) * 0.5);
            pig[i]->setPigEvent(false);
        }
        pigCount = newPigCount;
    } else if (getWheatEvent() == true) {
        int newWheatCount = 0;
            if (wheat[0]->getPesticideApplied() == true){
                cout << "A disease has spread throughout the wheat, 1/4 of your wheat have died." << endl;
                newWheatCount = (wheatCount) * 0.25;
                for (int i = newWheatCount; i < wheatCount; i++){
                    wheat[i - newWheatCount] = wheat[i];
                }
                wheatCount = newWheatCount;
            }

            if (wheat[0]->getPesticideApplied() == false){
                cout << "A disease has spread throughout the wheat, half of your wheat have died." << endl;
                newWheatCount = (wheatCount) * 0.5;
                for (int i = newWheatCount; i < wheatCount; i++){
                    wheat[i - newWheatCount] = wheat[i];
                }
                wheatCount = newWheatCount;
            }
    } else if (getCornEvent() == true) {
        int newCornCount = 0;
        if (corn[0]->getPesticideApplied() == true) {
            cout << "A disease has spread throughout the corn, 1/2 of your corn have died." << endl;
            newCornCount = cornCount * 0.5;
            for (int i = newCornCount; i < cornCount; i++){
                corn[i - newCornCount] = corn[i];
                corn[i]->setCornEvent(false);
            }
            cornCount = newCornCount;
        }
        if (corn[0]->getPesticideApplied() == false){
            cout << "A disease has spread throughout the corn, half of your corn have died." << endl;
            int newCornCount = cornCount * 0.5;
            for (int i = newCornCount; i < cornCount; i++){
                corn[i - newCornCount] = corn[i];
                corn[i]->setCornEvent(false);
            }
            cornCount = newCornCount;
        }
    }
}

Farmer::~Farmer() {
    for (int i = 0; i < cowCount; i++){
        delete cow[i];
    }
    for (int i = 0; i < pigCount; i++){
        delete pig[i];
    }
    for (int i = 0; i < wheatCount; i++){
        delete wheat[i];
    }
    for (int i = 0; i < cornCount; i++){
        delete corn[i];
    }
    delete[] cow;
    delete[] pig;
    delete[] wheat;
    delete[] corn;
}
