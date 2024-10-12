#include "Farmer.h"

luytrertyuytrewertytrewertyuytrertyuytrertytrertytre
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

/*void Farmer::buyCorn(Corn**& cornArray, int& cornCount, int amount) {
    // Resize logic for the corn array
    Corn** newCornArray = new Corn*[cornCount + amount];

    // Copy existing corn pointers to the new array
    for (int i = 0; i < cornCount; ++i) {
        newCornArray[i] = cornArray[i];
    }

    // Create new corn objects and add them to the new array
    for (int j = 0; j < amount; ++j) {
        newCornArray[cornCount + j] = new Corn(); // Allocate a single Corn object
    }

    // Delete the old corn array and reassign
    delete[] cornArray;
    cornArray = newCornArray; // Update the pointer to the new array
    cornCount += amount; // Update the total count of corn
}
*/

void Farmer::buyAnimal(){
    string newProduct;
    cout << "What animal would you like to buy? enter pig or cow" << endl;
    cin >> newProduct;
    setProduct(newProduct);
    while (getProduct() != "pig" && getProduct() != "cow") {
        cout << "invalid input! please enter pig or cow" << endl;
        cin >> product;
    }
    int amount = 0;

    if (getProduct() == "cow") {
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
        Cow** newCowArray = new Cow*[cowCount + amount];
        
        for (int i = 0; i < cowCount + amount; i++){
            newCowArray[i] = nullptr;
        }

        for (int i = cowCount-1; i < cowCount + amount; i++){
            Cow* newCow = createNewCow();
            newCowArray[i] = newCow;
        }

        delete[] cow;
        cow = newCowArray;
        setCowCount(cowCount + amount);

    } else if(getProduct() == "pig") {
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
        Pig** newPigArray = new Pig*[pigCount + amount];
        
        for (int i = 0; i < pigCount + amount; i++){
            newPigArray[i] = nullptr;
        }

        for (int i = pigCount-1; i < pigCount + amount; i++){
            Pig* newPig = createNewPig();
            newPigArray[i] = newPig;
        }

        delete[] pig;
        pig = newPigArray;
        setPigCount(pigCount + amount);
    }
}

void Farmer::sellAnimal(){
    cout << "What animal would you like to sell, cow or pig? (Enter response in lower case)" << endl;
    cin >> product;
    while (product != "cow" && product != "pig") {
        cout << "invalid input! please enter cow or pig" << endl;
        cin >> product;
    }
    if (product == "cow") {
        string optionChoice;
        time_t currentTime = time(0); 
        int j = 0;
        int readyToSellCount = 0;
        int newMoney = 0;
        for (int i = 0; i < cowCount; ++i) {
            if (currentTime - (cow[i]->getTimer()) >= cow[i]->getSellTime()) {
                newMoney = newMoney + cow[i]->getSellPrice();
                readyToSellCount++;
            }
        }
        Cow** newCowArray = new Cow*[cowCount - readyToSellCount];
        cout << "you have " << readyToSellCount << " cows to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == "Y") {
            for (int i = 0; i < cowCount; ++i) {
                if ((currentTime - (cow[i]->getTimer())) < cow[i]->getSellTime()){
                    newCowArray[j] = cow[i];
                    j++;
                } else {
                    delete cow[i];
                }
            }
            money = money + newMoney;
            cow = newCowArray;
            setCowCount(cowCount - readyToSellCount);
        }

    } else if (product == "pig") {
        string optionChoice;
        time_t currentTime = time(0); 
        int j = 0;
        int readyToSellCount = 0;
        int newMoney = 0;
        for (int i = 0; i < pigCount; ++i) {
            if (currentTime - (pig[i]->getTimer()) >= pig[i]->getSellTime()) {
                newMoney = newMoney + pig[i]->getSellPrice();
                readyToSellCount++;
            }
        }
        Pig** newPigArray = new Pig*[pigCount - readyToSellCount];
        cout << "you have " << readyToSellCount << " pigs to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == "Y") {
            for (int i = 0; i < pigCount; ++i) {
                if ((currentTime - (pig[i]->getTimer())) < pig[i]->getSellTime()){
                    newPigArray[j] = pig[i];
                    j++;
                } else {
                    delete pig[i];
                }
            }
            money = money + newMoney;
            pig = newPigArray;
            setPigCount(pigCount - readyToSellCount);
        }
    }   
}

void Farmer::buyCrop() {
    string newProduct;
    cout << "What crop would you like to buy? enter wheat or corn" << endl;
    cin >> newProduct;
    setProduct(newProduct);
    while (getProduct() != "wheat" && getProduct() != "corn") {
        cout << "invalid input! please enter wheat or corn" << endl;
        cin >> product;
    }
    int amount = 0;

    if (getProduct() == "wheat") {
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

        Wheat** newWheatArray = new Wheat*[wheatCount + amount];
        
        for (int i = 0; i < wheatCount + amount; i++){
            newWheatArray[i] = nullptr;
        }

        for (int i = wheatCount-1; i < wheatCount + amount; i++){
            Wheat* newWheat = createNewWheat();
            newWheatArray[i] = newWheat;
        }

        delete[] wheat;
        wheat = newWheatArray;
        setWheatCount(wheatCount + amount);

    } else if (getProduct() == "corn"){
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
        Corn** newCornArray = new Corn*[cornCount + amount];
        
        for (int i = 0; i < cornCount + amount; i++){
            newCornArray[i] = nullptr;
        }

        for (int i = cornCount-1; i < cornCount + amount; i++){
            Corn* newCorn = createNewCorn();
            newCornArray[i] = newCorn;
        }

        delete[] corn;
        corn = newCornArray;
        setCornCount(cornCount + amount);
    }
}

string Farmer::getProduct(){
    return product;
}

void Farmer::setProduct(string product){
    this -> product = product;
}

void Farmer::sellCrop(){
    cout << "What crop would you like to sell, wheat or corn? (Enter response in lower case)" << endl;
    cin >> product;
    while (product != "wheat" && product != "corn") {
        cout << "invalid input! please enter wheat or corn" << endl;
        cin >> product;
    }

    if (product == "wheat"){
        string optionChoice;
        time_t currentTime = time(0); 
        int j = 0;
        int readyToSellCount = 0;
        int newMoney = 0;
        for (int i = 0; i < wheatCount; ++i) {
            if (currentTime - (wheat[i]->getTimer()) >= wheat[i]->getSellTime()) {
                newMoney = newMoney + wheat[i]->getSellPrice();
                readyToSellCount++;
            }
        }
        Wheat** newWheatArray = new Wheat*[wheatCount - readyToSellCount];
        cout << "you have " << readyToSellCount << " wheat to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == "Y") {
            for (int i = 0; i < wheatCount; ++i) {
                if ((currentTime - (wheat[i]->getTimer())) < wheat[i]->getSellTime()){
                    newWheatArray[j] = wheat[i];
                    j++;
                } else {
                    delete wheat[i];
                }
            }
            money = money + newMoney;
            wheat = newWheatArray;
            setWheatCount(wheatCount - readyToSellCount);
        }
        
    } else if (getProduct() == "corn") {
        string optionChoice;
        time_t currentTime = time(0); 
        int j = 0;
        int readyToSellCount = 0;
        int newMoney = 0;
        for (int i = 0; i < cornCount; ++i) {
            cout << "Yo" << endl;
            if (corn[i]->isReadyToSell() == true){
            newMoney = newMoney + corn[i]->getSellPrice();
            readyToSellCount++;
            }
        }
        Corn** newCornArray = new Corn*[cornCount - readyToSellCount];
        cout << "you have " << readyToSellCount << " corn to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == "Y") {
            for (int i = 0; i < cornCount-1; ++i) {
                if (corn[i]->isReadyToSell() == false){
                newCornArray[j++] = corn[i];
                }
            }
            money = money + newMoney;
            corn = newCornArray;
            setCornCount(cornCount - readyToSellCount);
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

void Farmer::fieldSpeedGrowthBought() {
    if(corn[0]->getFieldSpeedGrowthApplied() == true) {
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

void Farmer:: barnSpeedGrowthBought(){
        if (cow[0]->getBarnSpeedGrowthApplied() == true) {
        for (int i = 0; i < *getCowCount() ; i++) {
            cow[i]->setSellTime((cow[i]->getSellTime())-1);
            cow[i]->setBarnSpeedGrowthApplied(false);
        }
        for (int i = 0; i < *getPigCount() ; i++) {
            pig[i]->setSellTime((pig[i]->getSellTime())-1);
            pig[i]->setBarnSpeedGrowthApplied(false);
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

// the read and write files were written using information from the week 5 lecture video and https://stackoverflow.com/questions/132358/how-to-read-file-content-into-istringstream
void Farmer::fileReader(string filename) {
    inputFile.open(filename, ios::in);
    int newMoney;
    inputFile >> newMoney;
    inputFile.close();
    setMoneyCount(newMoney);

}

void Farmer::fileWriter(string filename, int* money) {

    outputFile.open(filename, ios::out);
    outputFile << *money << endl;
    outputFile.close();
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
