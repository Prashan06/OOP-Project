#include "Farmer.h"
#include <iostream>
// Constructor 
/* Farmer::Farmer() : money(50), pig(new Pig*[pigCount]), cow(new Cow*[cowCount]), wheat(new Wheat*[wheatCount]), corn(new Corn*[cornCount]), farmName(""), timesWheatPlanted(0), timesCornPlanted(0), timesCowsBought(0), timesPigsBought(0) {}

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
        // Asks user for the farm name and puts that into the variable farmName.
        cout << "What would you like to call your farm? (max 20 characters): " << endl;
        cin >> farmName;
        int i = 0;
        while (farmName[i] != '\0'){
            i++;
        }
        // checks if the farmName is less that 21 characters include the null terminator. If not, outputs an error message
        // and asks user to reenter the farm name.
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

// returns the farm name, money, and the amount of pigs, cows, sheep, and wheat in the farm..
void Farmer:: getStatus(){
    std::cout << "Hello " << getFarmName() << std::endl;
    std::cout << "Your bank account holds: " << *getMoneyCount() << " Dollars" << std::endl;
    std::cout << "You have " << cowCount << " cows" << std::endl;
    std::cout << "You have " << pigCount << " pigs" << std::endl;
    std::cout << "You have " << cornCount << " corns" << std::endl;
    std::cout << "You have " << wheatCount << " wheat" << std::endl;
}

// creates a cow object
Cow* Farmer::createNewCow() {
    Cow* newCow = new Cow;
    return new Cow;
}

// creates a pig object
Pig* Farmer::createNewPig() {
    Pig* newPig = new Pig;
    return newPig;
}

//creates a wheat object.
Wheat* Farmer::createNewWheat() {
    Wheat* newWheat = new Wheat;
    return newWheat;
}

//creates a corn object
Corn* Farmer::createNewCorn() {
    Corn* newCorn = new Corn;
    return newCorn;
}

*/

// This function is used to buy pig and cow objects and put them into the pig or cow array.
void Farmer::buyAnimal(){
    // Asks user what animal they would like to buy and puts their response into the product variables.
    string newProduct;
    cout << "What animal would you like to buy? enter pig or cow" << endl;
    cin >> newProduct;
    setProduct(newProduct);
    // Asks user again for an input if their response in not pig or cow.
    while (getProduct() != "pig" && getProduct() != "cow") {
        cout << "invalid input! please enter pig or cow" << endl;
        cin >> product;
    }
    int amount = 0;

    // If the user types in cow, the code will prompt the user to type in how may cows they would like to buy and puts this into the amount variable.
    if (getProduct() == "cow") {
        Cow tempCow;
        cout << "How many cows would you like to buy?, you can buy " << money/tempCow.getBuyPrice() << " cows" << endl;
        cin >> amount;
        // figure out how much the user has to pay.
        int amountPaid = tempCow.getBuyPrice() * amount;
        // Outputs message notifying user that they do not have enough money to buy cows
        // and asks user to enter a new amount. 
        while (money < amountPaid ) {
            cout << "You do not have enough money to buy " << amount << " cows" << endl;
            cout << "enter a new amount: ";
            cin >> amount;
        }
        // decreasese the users money.
        money = money - amountPaid;
        // Initalises a new array that has enough space read in the cow objects after the buying process.
        Cow** newCowArray = new Cow*[cowCount + amount];
        // Intialises the elements in the newCowArray to null pointers
        for (int i = 0; i < cowCount + amount; i++){
            newCowArray[i] = nullptr;
        }
        // copies the current elements in cow into the newCowArray.
        for (int i = 0; i < cowCount; i++){
            newCowArray[i] = cow[i];
        }
        // creates cow objects and adds them to the newCowArray.
        for (int i = cowCount; i < cowCount + amount; i++){
            Cow* newCow = createNewCow();
            newCowArray[i] = newCow;
        }
         // deletes the cow array.
        delete[] cow;
        // The cow variable is now assigned to the newCowArray.
        cow = newCowArray;
        //sets cowCount.
        setCowCount(cowCount + amount);
        for (int i = 0; i < cowCount; i++){
            cow[i]->Event(getCowCount());
        }
    // if the user enters pig, the code for buying pigs runs
    } else if(getProduct() == "pig") {
        Pig tempPig;
        // Message notifying user that they are buying pigs.
        cout << "How many pigs would you like to buy?, you can buy " << money/tempPig.getBuyPrice() << " pigs" << endl;
        cin >> amount;
        // Amount user has to pay to buy the pigs.
        int amountPaid = tempPig.getBuyPrice() * amount;
        // Notifies user that they do not have enough money to buy pigs and asks them to enter an amount they can afford.
        while (money < amountPaid ) {
            cout << "You do not have enough money to buy " << amount << " pigs" << endl;
            cout << "enter a new amount: ";
            cin >> amount;
        }
        // decreasese the users money.
        money = money - amountPaid;
        // Initalises a new array that has enough space read in the pigs objects after the buying process.
        Pig** newPigArray = new Pig*[pigCount + amount];
        // Intialises the elements in the newPigsArray to null pointers
        for (int i = 0; i < pigCount + amount; i++){
            newPigArray[i] = nullptr;
        }
        // copies the current elements in pigs into the newPigArray.
        for (int i = 0; i < pigCount; i++){
            newPigArray[i] = pig[i];
        }
        // creates pigs objects and adds them to the newPigArray.
        for (int i = pigCount; i < pigCount + amount; i++){
            Pig* newPig = createNewPig();
            newPigArray[i] = newPig;
        }
        // Deletes the pig array.
        delete[] pig;
        // The pig variable is now assigned to the newPigArray.
        pig = newPigArray;
        //sets the pigCount.
        setPigCount(pigCount + amount);
        for (int i = 0; i < cowCount; i++){
            pig[i]->Event(getPigCount());
        }
    }
}

//This function sells (deletes) the cow and pigs objects in the cow and wheat array.
void Farmer::sellAnimal(){
    // Asks the user what animal they would like to sell and puts their input to the variable product.
    cout << "What animal would you like to sell, cow or pig? (Enter response in lower case)" << endl;
    cin >> product;
    // Asks the user to enter a valid input.
    while (product != "cow" && product != "pig") {
        cout << "invalid input! please enter cow or pig" << endl;
        cin >> product;
    }
    // If the user entered cow, the code to sell cow will run.
    if (product == "cow") {
        string optionChoice;
        time_t currentTime = time(0); 
        int j = 0;
        int readyToSellCount = 0;
        int newMoney = 0;
        // This for loop determines how many cow objects are ready to be sold and increments readyToSellCount.
        for (int i = 0; i < cowCount; ++i) {
            if (currentTime - (cow[i]->getTimer()) >= cow[i]->getSellTime()) {
                newMoney = newMoney + cow[i]->getSellPrice();
                readyToSellCount++;
            }
        }
        // Initalises a new array that has enough space read in the cow objects after the selling process.
        Cow** newCowArray = new Cow*[cowCount - readyToSellCount];
        // Message to confirm that the user wants to sell. Their response if read into the optionChoice.
        cout << "you have " << readyToSellCount << " cows to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        cin >> optionChoice;
        // Asks user for a valid input if their previous input was invalid.
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        // If the user input Y, the selling process begins
        if (optionChoice == "Y") {
            for (int i = 0; i < cowCount; ++i) {
                //  This takes the cow objects in the cow array that are not ready to be sold and puts them into the the newCowArray.
                if ((currentTime - (cow[i]->getTimer())) < cow[i]->getSellTime()){
                    newCowArray[j] = cow[i];
                    j++;
                } else {
                    // if the objects are ready to be sold, that object in the wheat array is deleted.
                    delete cow[i];
                }
            }
            // increases the money that the farmer has.
            money = money + newMoney;
            //deletes the current cow array.
            delete [] cow;
            // The cow variable is now assigned to the newCowArray.
            cow = newCowArray;
            // sets thhe cowCount.
            setCowCount(cowCount - readyToSellCount);
        }
    // If the user entered pig, the code to sell wheat will run.
    } else if (product == "pig") {
        string optionChoice;
        time_t currentTime = time(0); 
        int j = 0;
        int readyToSellCount = 0;
        int newMoney = 0;
        // This for loop determines how many pig objects are ready to be sold and increments readyToSellCount.
        for (int i = 0; i < pigCount; ++i) {
            if (currentTime - (pig[i]->getTimer()) >= pig[i]->getSellTime()) {
                newMoney = newMoney + pig[i]->getSellPrice();
                readyToSellCount++;
            }
        }
        // Initalises a new array that has enough space read in the pig objects after the selling process.
        Pig** newPigArray = new Pig*[pigCount - readyToSellCount];
        // Message to confirm that the user wants to sell. Their response if read into the optionChoice.
        cout << "you have " << readyToSellCount << " pigs to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        cin >> optionChoice;
        // Asks user for a valid input if their previous input was invalid.
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        // If the user input Y, the selling process begins
        if (optionChoice == "Y") {
            for (int i = 0; i < pigCount; ++i) {
                //  This takes the pig objects in the pig array that are not ready to be sold and puts them into the the newPigArray.
                if ((currentTime - (pig[i]->getTimer())) < pig[i]->getSellTime()){
                    newPigArray[j] = pig[i];
                    j++;
                } else {
                    // if the objects are ready to be sold, that object in the pig array is deleted.
                    delete pig[i];
                }
            }
            // increases the money the farmer has.
            money = money + newMoney;
            //deletes the current pig array.
            delete [] pig;
            // The pig variable is now assigned to the newPigArray.
            pig = newPigArray;
            // sets the pigCount
            setPigCount(pigCount - readyToSellCount);
        }
    }   
}

//This functions buys (creates and stores corn or wheat objects in the wheat or corn array)
void Farmer::buyCrop() {
    string newProduct;
    // Asks user what crop they want to buy and puts this into the newProduct variables
    cout << "What crop would you like to buy? enter wheat or corn" << endl;
    cin >> newProduct;
    //sets the product variables
    setProduct(newProduct);
    // Asks user to enter a valid input if the previous input was invalid.
    while (getProduct() != "wheat" && getProduct() != "corn") {
        cout << "invalid input! please enter wheat or corn" << endl;
        cin >> product;
    }
    int amount = 0;
    // if the user enters wheat, the code for buying wheat runs
    if (getProduct() == "wheat") {
        Wheat tempWheat;
        // Message notifying user that they are buying wheat.
        cout << "How many wheat crops would you like to buy?, you can buy " << money/tempWheat.getBuyPrice() << " wheat" << endl;
        cin >> amount;
        // Amount user has to pay to buy the wheat
        int amountPaid = tempWheat.getBuyPrice() * amount;
        // Notifies user that they do not have enough money to buy wheat and asks them to enter an amount they can afford.
        while (money < amountPaid ) {
            cout << "You do not have enough money to buy " << amount << " wheat" << endl;
            cout << "enter a new amount: ";
            cin >> amount;
        }
        // decreasese the users money.
        money = money - amountPaid;

        // Initalises a new array that has enough space read in the wheat objects after the buying process.
        Wheat** newWheatArray = new Wheat*[wheatCount + amount];
        // Intialises the elements in the newWheatArray to null pointers
        for (int i = 0; i < wheatCount + amount; i++){
            newWheatArray[i] = nullptr;
        }
        // copies the current elements in wheat into the newWheatArray.
        for (int i = 0; i < wheatCount; i++){
            newWheatArray[i] = wheat[i];
        }
        // creates wheat objects and adds them to the newWheatArray.
        for (int i = wheatCount; i < wheatCount + amount; i++){
            Wheat* newWheat = createNewWheat();
            newWheatArray[i] = newWheat;
        }

        // deletes the wheat array.
        delete[] wheat;
        // The wheat variable is now assigned to the newWheatArray.
        wheat = newWheatArray;
        // sets the wheat count.
        setWheatCount(wheatCount + amount);
    // if the user enters corn, the code for buying corn runs
        for (int i = 0; i < wheatCount; i++){
            wheat[i]->Event(getWheatCount());
        }
    } else if (getProduct() == "corn"){
        Corn tempCorn;
        // Message notifying user that they are buying corn.
        cout << "How many corn crops would you like to buy?, you can buy " << money/tempCorn.getBuyPrice() << " corn" << endl;
        cin >> amount;
        // Amount user has to pay to buy the corn.
        int amountPaid = tempCorn.getBuyPrice() * amount;
        // Notifies user that they do not have enough money to buy corn and asks them to enter an amount they can afford.
        while (money < amountPaid ) {
            cout << "You do not have enough money to buy " << amount << " corn" << endl;
            cout << "enter a new amount: ";
            cin >> amount;
        }
        // decreasese the users money.
        money = money - amountPaid;
        // Initalises a new array that has enough space read in the corn objects after the buying process.
        Corn** newCornArray = new Corn*[cornCount + amount];
        // Intialises the elements in the newCornArray to null pointers
        for (int i = 0; i < cornCount + amount; i++){
            newCornArray[i] = nullptr;
        }
        // copies the current elements in corn into the newCornArray.
        for (int i = 0; i < cornCount; i++){
            newCornArray[i] = corn[i];
        }
        // creates corn objects and adds them to the newCornArray.
        for (int i = cornCount; i < cornCount + amount; i++){
            Corn* newCorn = createNewCorn();
            newCornArray[i] = newCorn;
        }
        // deletes the corn array.
        delete[] corn;
        // The corn variable is now assigned to the newCornArray.
        corn = newCornArray;
        // sets the cornCount.
        setCornCount(cornCount + amount);
        for (int i = 0; i < cornCount; i++){
            corn[i]->Event(getCornCount());
        }
    }
}

// returns the product variables.
string Farmer::getProduct(){
    return product;
}

// sets the product variable.
void Farmer::setProduct(string product){
    this -> product = product;
}

//This function sells (deletes) the corn and wheat objects in the corn and wheat array.
void Farmer::sellCrop(){
    // Asks the user what crop they would like to sell and puts their input to the variable product.
    cout << "What crop would you like to sell, wheat or corn? (Enter response in lower case)" << endl;
    cin >> product;
    // Asks the user to enter a valid input.
    while (product != "wheat" && product != "corn") {
        cout << "invalid input! please enter wheat or corn" << endl;
        cin >> product;
    }
    // If the user entered wheat, the code to sell wheat will run.
    if (product == "wheat"){
        string optionChoice;
        time_t currentTime = time(0); 
        int j = 0;
        int readyToSellCount = 0;
        int newMoney = 0;
        // This for loop determines how many wheat objects are ready to be sold and increments readyToSellCount.
        for (int i = 0; i < wheatCount; ++i) {
            if (currentTime - (wheat[i]->getTimer()) >= wheat[i]->getSellTime()) {
                newMoney = newMoney + wheat[i]->getSellPrice();
                readyToSellCount++;
            }
        }
        // Initalises a new array that has enough space read in the wheat objects after the selling process.
        Wheat** newWheatArray = new Wheat*[wheatCount - readyToSellCount];
        // Message to confirm that the user wants to sell. Their response if read into the optionChoice.
        cout << "you have " << readyToSellCount << " wheat to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        cin >> optionChoice;
        // Asks user for a valid input if their previous input was invalid.
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        // If the user input Y, the selling process begins
        if (optionChoice == "Y") {
            for (int i = 0; i < wheatCount; ++i) {
                //  This takes the wheat objects in the wheat array that are not ready to be sold and puts them into the the newWheatArray.
                if ((currentTime - (wheat[i]->getTimer())) < wheat[i]->getSellTime()){
                    newWheatArray[j] = wheat[i];
                    j++;
                } else {
                    // if the objects are ready to be sold, that object in the wheat array is deleted.
                    delete wheat[i];
                }
            }
            // increases the money that the farmer has.
            money = money + newMoney;
            //deletes the current wheat array.
            delete [] wheat;
            // The pointer of wheat array will now point at the newWheat Array.
            wheat = newWheatArray;
            // sets the wheatCount
            setWheatCount(wheatCount - readyToSellCount);
        }
     // If the user entered corn, the code to sell wheat will run.
    } else if (getProduct() == "corn") {
        string optionChoice;
        time_t currentTime = time(0); 
        int j = 0;
        int readyToSellCount = 0;
        int newMoney = 0;
         // This for loop determines how many corn objects are ready to be sold and increments readyToSellCount.
        for (int i = 0; i < cornCount; ++i) {
            if (corn[i]->isReadyToSell() == true){
            newMoney = newMoney + corn[i]->getSellPrice();
            readyToSellCount++;
            }
        }
        // Initalises a new array that has enough space read in the corn objects after the selling process.
        Corn** newCornArray = new Corn*[cornCount - readyToSellCount];
        // Message to confirm that the user wants to sell. Their response if read into the optionChoice.
        cout << "you have " << readyToSellCount << " corn to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        cin >> optionChoice;
        // Asks user for a valid input if their previous input was invalid.
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        // If the user input Y, the selling process begins
        if (optionChoice == "Y") {
            for (int i = 0; i < wheatCount; ++i) {
                //  This takes the corn objects in the corn array that are not ready to be sold and puts them into the the newCornArray.
                if ((currentTime - (corn[i]->getTimer())) < corn[i]->getSellTime()){
                    newCornArray[j] = corn[i];
                    j++;
                } else {
                    // if the objects are ready to be sold, that object in the corn array is deleted.
                    delete corn[i];
                }
        }
        // increases the money that the farmer has.
            money = money + newMoney;
            //deletes the current corn array.
            delete [] corn;
             // The pointer of corn array will now point at the newCornArray.
            corn = newCornArray;
            // sets the cornCount.
            setCornCount(cornCount - readyToSellCount);
        }
    }
}

/*
// setter for cowCount
void Farmer::setCowCount(int cowCount){
    this->cowCount = cowCount;
}

// setter for pigCount
void Farmer::setPigCount(int pigCount){
    this->pigCount = pigCount;
}

// setter for wheatCount
void Farmer::setWheatCount(int wheatCount){
    this->wheatCount = wheatCount;
}

// setter for cornCount
void Farmer::setCornCount(int cornCount){
    this->cornCount = cornCount;
}

// return the address of the cowCount.
int* Farmer::getCowCount(){
    return &cowCount;
}

// return the address of the pigCount.
int* Farmer::getPigCount(){
    return &pigCount;
}

// return the address of the wheatCount.
int* Farmer::getWheatCount(){
    return &wheatCount;
}

// return the address of the cornCount.
int* Farmer::getCornCount(){
    return &cornCount;
}

// returns a double pointer to the first element of the cow array.
Cow** Farmer::getCowArray() {
    return cow;
}

// returns a double pointer to the first element of the pig array.
Pig** Farmer::getPigArray() {
    return pig;
}

// returns a double pointer to the first element of the wheat array.
Wheat** Farmer::getWheatArray() {
    return wheat;
}

// returns a double pointer to the first element of the corn array.
Corn** Farmer::getCornArray() {
    return corn;
}

// This function decreases the sellTime of the corn and wheat.
void Farmer::fieldSpeedGrowthBought() {
    // If the user wants to buy fieldSpeedGrow (fieldSpeedGrow will be true), the below code runs.
    if(corn[0]->getFieldSpeedGrowthApplied() == true) {
        for (int i = 0; i < *getCornCount() ; i++) {
            // Decreases the sellTime of each corn object in the corn array.
            corn[i]->setSellTime((corn[i]->getSellTime())-1);
            // sets the fieldSpeedGrowth to false, ready for the next time the user wants to buy speedGrow.
            corn[i]->setBarnSpeedGrowthApplied(false);
        }
        for (int i = 0; i < *getWheatCount() ; i++) {
            // Decreases the sellTime of each wheat object in the wheat array.
            wheat[i]->setSellTime((wheat[i]->getSellTime())-1);
            // sets the fieldSpeedGrowth to false, ready for the next time the user wants to buy speedGrow.
            wheat[i]->setBarnSpeedGrowthApplied(false);
        }
    }

}

// This function decreases the sellTime of the cows and pigs.
void Farmer:: barnSpeedGrowthBought(){
    // If the user wants to buy barnSpeedGrow (barnSpeedGrow will be true), the below code runs.
        if (cow[0]->getBarnSpeedGrowthApplied() == true) {
            // Decreases the sellTime of each cow object in the cow array.
        for (int i = 0; i < *getCowCount() ; i++) {
            cow[i]->setSellTime((cow[i]->getSellTime())-1);
            // sets the BarnSpeedGrowth to false, ready for the next time the user wants to buy speedGrow.
            cow[i]->setBarnSpeedGrowthApplied(false);
        }
        for (int i = 0; i < *getPigCount() ; i++) {
            // Decreases the sellTime of each pig object in the pig array.
            pig[i]->setSellTime((pig[i]->getSellTime())-1);
            // sets the BarnSpeedGrowth to false, ready for the next time the user wants to buy speedGrow.
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

// Deletes the elements inside the arrays and then deletes the array.
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
} */

#include "Farmer.h"
#include <iostream>

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
        std::cout << "What would you like to call your farm? (max 20 characters): " << endl;
        std::cin >> farmName;
        int i = 0;
        while (farmName[i] != '\0'){
            i++;
        }
        if (i > 20){
            std::cout << "Farm name is too long, please enter a shorter one." << endl;
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

/* void Farmer::buyAnimal(){
    string newProduct;
    std::cout << "What animal would you like to buy? enter pig or cow" << endl;
    std::cin >> newProduct;
    setProduct(newProduct);
    while (getProduct() != "pig" && getProduct() != "cow") {
        std::cout << "invalid input! please enter pig or cow" << endl;
        std::cin >> product;
    }
    int amount = 0;

    if (getProduct() == "cow") {
        Cow tempCow;
        std::cout << "How many cows would you like to buy?, you can buy " << money/tempCow.getBuyPrice() << " cows" << endl;
        std::cin >> amount;
        int amountPaid = tempCow.getBuyPrice() * amount;
        while (money < amountPaid ) {
            std::cout << "You do not have enough money to buy " << amount << " cows" << endl;
            std::cout << "enter a new amount: ";
            std::cin >> amount;
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
        std::cout << "How many pigs would you like to buy?, you can buy " << money/tempPig.getBuyPrice() << " pigs" << endl;
        std::cin >> amount;
        int amountPaid = tempPig.getBuyPrice() * amount;
        while (money < amountPaid ) {
            std::cout << "You do not have enough money to buy " << amount << " pigs" << endl;
            std::cout << "enter a new amount: ";
            std::cin >> amount;
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
    std::cout << "What animal would you like to sell, cow or pig? (Enter response in lower case)" << endl;
    std::cin >> product;
    while (product != "cow" && product != "pig") {
        std::cout << "invalid input! please enter cow or pig" << endl;
        std::cin >> product;
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
        std::cout << "you have " << readyToSellCount << " cows to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        std::cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            std::cout << "invalid input! please enter Y or N" << endl;
            std::cin >> optionChoice;
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
        std::cout << "you have " << readyToSellCount << " pigs to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        std::cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            std::cout << "invalid input! please enter Y or N" << endl;
            std::cin >> optionChoice;
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
    std::cout << "What crop would you like to buy? enter wheat or corn" << endl;
    std::cin >> newProduct;
    setProduct(newProduct);
    while (getProduct() != "wheat" && getProduct() != "corn") {
        std::cout << "invalid input! please enter wheat or corn" << endl;
        std::cin >> product;
    }
    int amount = 0;

    if (getProduct() == "wheat") {
        Wheat tempWheat;
        std::cout << "How many wheat crops would you like to buy?, you can buy " << money/tempWheat.getBuyPrice() << " wheat" << endl;
        std::cin >> amount;
        int amountPaid = tempWheat.getBuyPrice() * amount;
        while (money < amountPaid ) {
            std::cout << "You do not have enough money to buy " << amount << " wheat" << endl;
            std::cout << "enter a new amount: ";
            std::cin >> amount;
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
        std::cout << "How many corn crops would you like to buy?, you can buy " << money/tempCorn.getBuyPrice() << " corn" << endl;
        std::cin >> amount;
        int amountPaid = tempCorn.getBuyPrice() * amount;
        while (money < amountPaid ) {
            std::cout << "You do not have enough money to buy " << amount << " corn" << endl;
            std::cout << "enter a new amount: ";
            std::cin >> amount;
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
    std::cout << "What crop would you like to sell, wheat or corn? (Enter response in lower case)" << endl;
    std::cin >> product;
    while (product != "wheat" && product != "corn") {
        std::cout << "invalid input! please enter wheat or corn" << endl;
        std::cin >> product;
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
        std::cout << "you have " << readyToSellCount << " wheat to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        std::cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            std::cout << "invalid input! please enter Y or N" << endl;
            std::cin >> optionChoice;
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
            std::cout << "Yo" << endl;
            if (corn[i]->isReadyToSell() == true){
            newMoney = newMoney + corn[i]->getSellPrice();
            readyToSellCount++;
            }
        }
        Corn** newCornArray = new Corn*[cornCount - readyToSellCount];
        std::cout << "you have " << readyToSellCount << " corn to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        std::cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            std::cout << "invalid input! please enter Y or N" << endl;
            std::cin >> optionChoice;
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

*/

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
/*
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
*/



void Farmer::applySpeedGrowAnimals(){

    string product;

    Wheat functionWheat;
    Corn functionCorn;
    Pig functionPig;
    Cow functionCow;

    std::cout << "What crop would you like to upgrade? cow or pig? (Enter response in lower case)" << endl;
    std::cin >> product;

    while (product != "pig" && product != "cow"){
        std::cout << "invalid input! please enter cow or pig" << endl;
        std::cin >> product;
    }


    if (product == "pig"){

        
        int option;
        int newMoney = 0;
        int highYieldNotAppliedCount;

        int numberCanUpgrade = money/functionPig.getHighYieldPrice();

        if (numberCanUpgrade > pigCount){
            numberCanUpgrade = pigCount;
        }

        std::cout << "You can upgrade " << numberCanUpgrade << " pigs" << endl;
        std::cout << "Enter the number that you would like to upgrade or 0 to exit" << endl;
        int optionChoice = 0;
        std::cin >> optionChoice;
        while (optionChoice < 0 || optionChoice > numberCanUpgrade){
            std::cout << "invalid input! please enter a valid number" << endl;
        }
        if (optionChoice != 0) {
            int j = 0;
            for (int i = 0; i < pigCount; ++i) {
                if (j < optionChoice){
                    pig[i]->applyHighYield(&money);
                    j++;
                } else {
                    break;
                }
            }
        }

    }else if (product == "cow"){

        
        int option;
        int newMoney = 0;
        int highYieldNotAppliedCount;

        int numberCanUpgrade = money/functionCow.getHighYieldPrice();

        if (numberCanUpgrade > cowCount){
            numberCanUpgrade = cowCount;
        }

        std::cout << "You can upgrade " << numberCanUpgrade << " cows" << endl;
        std::cout << "Enter the number that you would like to upgrade or 0 to exit" << endl;
        int optionChoice = 0;
        std::cin >> optionChoice;
        while (optionChoice < 0 || optionChoice > numberCanUpgrade){
            std::cout << "invalid input! please enter a valid number" << endl;
        }
        if (optionChoice != 0) {
            int j = 0;
            for (int i = 0; i < cowCount; ++i) {
                if (j < optionChoice){
                    cow[i]->applyHighYield(&money);
                    j++;
                } else {
                    break;
                }
            }
        }
    }

} 

void Farmer::applyHighYieldAnimals(){

    string product;

    Wheat functionWheat;
    Corn functionCorn;
    Pig functionPig;
    Cow functionCow;

    std::cout << "What crop would you like to upgrade? cow or pig? (Enter response in lower case)" << endl;
    std::cin >> product;

    while (product != "pig" && product != "cow"){
        std::cout << "invalid input! please enter cow or pig" << endl;
        std::cin >> product;
    }


    if (product == "pig"){

        
        int option;
        int newMoney = 0;
        int highYieldNotAppliedCount;

        int numberCanUpgrade = money/functionPig.getHighYieldPrice();

        if (numberCanUpgrade > pigCount){
            numberCanUpgrade = pigCount;
        }

        std::cout << "You can upgrade " << numberCanUpgrade << " pigs" << endl;
        std::cout << "Enter the number that you would like to upgrade or 0 to exit" << endl;
        int optionChoice = 0;
        std::cin >> optionChoice;
        while (optionChoice < 0 || optionChoice > numberCanUpgrade){
            std::cout << "invalid input! please enter a valid number" << endl;
        }
        if (optionChoice != 0) {
            int j = 0;
            for (int i = 0; i < pigCount; ++i) {
                if (j < optionChoice){
                    pig[i]->applyHighYield(&money);
                    j++;
                } else {
                    break;
                }
            }
        }

    }else if (product == "cow"){

        
        int option;
        int newMoney = 0;
        int highYieldNotAppliedCount;

        int numberCanUpgrade = money/functionCow.getHighYieldPrice();

        if (numberCanUpgrade > cowCount){
            numberCanUpgrade = cowCount;
        }

        std::cout << "You can upgrade " << numberCanUpgrade << " cows" << endl;
        std::cout << "Enter the number that you would like to upgrade or 0 to exit" << endl;
        int optionChoice = 0;
        std::cin >> optionChoice;
        while (optionChoice < 0 || optionChoice > numberCanUpgrade){
            std::cout << "invalid input! please enter a valid number" << endl;
        }
        if (optionChoice != 0) {
            int j = 0;
            for (int i = 0; i < cowCount; ++i) {
                if (j < optionChoice){
                    cow[i]->applyHighYield(&money);
                    j++;
                } else {
                    break;
                }
            }
        }
    }

} 

/*

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

*/

void Farmer::applySpeedGrowCrops(){

    string product;

    Wheat functionWheat;
    Corn functionCorn;
    Pig functionPig;
    Cow functionCow;

    cout << "What crop would you like to upgrade? Wheat or Corn? (Enter response in lower case)" << endl;
    cin >> product;

    while (product != "wheat" && product != "corn"){
        cout << "invalid input! please enter wheat or corn" << endl;
        cin >> product;
    }

    if (product == "wheat"){

        int option;
        int newMoney = 0;
        int highYieldNotAppliedCount;

        int numberCanUpgrade = money/functionWheat.getSpeedGrowPrice();

        if (numberCanUpgrade > wheatCount){
            numberCanUpgrade = wheatCount;
        }

        std::cout << "You can upgrade " << numberCanUpgrade << " wheat" << endl;
        std::cout << "Enter the number that you would like to upgrade or 0 to exit" << endl;
        int optionChoice = 0;
        std::cin >> optionChoice;
        while (optionChoice < 0 || optionChoice > numberCanUpgrade){
            cout << "invalid input! please enter a valid number" << endl;
        }
        if (optionChoice != 0) {
            int j = 0;
            for (int i = 0; i < wheatCount; ++i) {
                if (j < optionChoice){
                    wheat[i]->applySpeedGrow(&money);
                    j++;
                } else {
                    break;
                }
            }

    }else if (product == "corn"){

                int option;
        int newMoney = 0;
        int highYieldNotAppliedCount;

        int numberCanUpgrade = money/functionCorn.getSpeedGrowPrice();

        if (numberCanUpgrade > cornCount){
            numberCanUpgrade = cornCount;
        }

        cout << "You can upgrade " << numberCanUpgrade << " corn" << endl;
        cout << "Enter the number that you would like to upgrade or 0 to exit" << endl;
        int optionChoice = 0;
        cin >> optionChoice;
        while (optionChoice < 0 || optionChoice > numberCanUpgrade){
            cout << "invalid input! please enter a valid number" << endl;
        }
        if (optionChoice != 0) {
            int j = 0;
            for (int i = 0; i < cornCount; ++i) {
                if (j < optionChoice){
                    corn[i]->applySpeedGrow(&money);
                    j++;
                } else {
                    break;
                }
            }
        }
    }

} 
}

void Farmer::applyHighYieldCrops(){

    string product;

    Wheat functionWheat;
    Corn functionCorn;
    Pig functionPig;
    Cow functionCow;

    cout << "What crop would you like to upgrade? Wheat or Corn? (Enter response in lower case)" << endl;
    cin >> product;

    while (product != "wheat" && product != "corn"){
        cout << "invalid input! please enter wheat or corn" << endl;
        cin >> product;
    }

    if (product == "wheat"){

        int option;
        int newMoney = 0;
        int highYieldNotAppliedCount;

        int numberCanUpgrade = money/functionWheat.getHighYieldPrice();

        if (numberCanUpgrade > wheatCount){
            numberCanUpgrade = wheatCount;
        }

        std::cout << "You can upgrade " << numberCanUpgrade << " wheat" << endl;
        std::cout << "Enter the number that you would like to upgrade or 0 to exit" << endl;
        int optionChoice = 0;
        std::cin >> optionChoice;
        while (optionChoice < 0 || optionChoice > numberCanUpgrade){
            cout << "invalid input! please enter a valid number" << endl;
        }
        if (optionChoice != 0) {
            int j = 0;
            for (int i = 0; i < wheatCount; ++i) {
                if (j < optionChoice){
                    wheat[i]->applyHighYield(&money);
                    j++;
                } else {
                    break;
                }
            }

    }else if (product == "corn"){

                int option;
        int newMoney = 0;
        int highYieldNotAppliedCount;

        int numberCanUpgrade = money/functionCorn.getHighYieldPrice();

        if (numberCanUpgrade > cornCount){
            numberCanUpgrade = cornCount;
        }

        cout << "You can upgrade " << numberCanUpgrade << " corn" << endl;
        cout << "Enter the number that you would like to upgrade or 0 to exit" << endl;
        int optionChoice = 0;
        cin >> optionChoice;
        while (optionChoice < 0 || optionChoice > numberCanUpgrade){
            cout << "invalid input! please enter a valid number" << endl;
        }
        if (optionChoice != 0) {
            int j = 0;
            for (int i = 0; i < cornCount; ++i) {
                if (j < optionChoice){
                    corn[i]->applyHighYield(&money);
                    j++;
                } else {
                    break;
                }
            }
        }
    }

} 
}

void Farmer::executeEvent() {
    if (getProduct() == "cow"){
        if (cow[9]->getCowEvent() == true && *getCowCount() > 9) {
            cout << "A disease has spread throughout the cows, half of your cows have died." << endl;
                int newCowCount = cowCount * 0.5;
                for (int i = newCowCount; i < cowCount; i++){
                    cow[i - newCowCount] = cow[i];
                    cow[i]->setCowEvent(false);
                }
            cowCount = newCowCount;
        }
    }
    if (getProduct() == "pig"){
        if (pig[9]->getPigEvent() == true && *getPigCount() > 9) {
            cout << "the demand for pig meat greatly decreased, in order to maintain a healthy flow of pigs " << endl;
            cout << "coming in and out of the farm, the sell price of all currently owned pigs must be reduced by half." << endl;
            for (int i = 0; i < pigCount; i++){
                pig[i]->setSellPrice((pig[i]->getSellPrice()) * 0.5);
                pig[i]->setPigEvent(false);
            }
        }
    }
    if (getProduct() == "wheat"){
     if (wheat[9] -> getWheatEvent() == true && *getWheatCount() > 9) {
        int newWheatCount = 0;
            if (wheat[9]->getPesticideApplied() == true){
                cout << "A disease has spread throughout the wheat, 1/4 of your wheat have died." << endl;
                newWheatCount = (wheatCount) * 0.25;
                for (int i = newWheatCount; i < wheatCount; i++){
                    wheat[i - newWheatCount] = wheat[i];
                    wheat[i]->setWheatEvent(false);
                }
                wheatCount = newWheatCount;
            }

            if (wheat[9]->getPesticideApplied() == false){
                cout << "A disease has spread throughout the wheat, half of your wheat have died." << endl;
                newWheatCount = (wheatCount) * 0.5;
                for (int i = newWheatCount; i < wheatCount; i++){
                    wheat[i - newWheatCount] = wheat[i];
                    wheat[i]->setWheatEvent(false);
                }
                wheatCount = newWheatCount;
            }
        }
     }
     if (getProduct() == "corn"){
        if (corn[9]->getCornEvent() == true && *getCornCount() > 9) {
            int newCornCount = 0;
                cout << "A disease has spread throughout the corn, 1/4 of your corn have died." << endl;
                newCornCount = cornCount * 0.25;
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