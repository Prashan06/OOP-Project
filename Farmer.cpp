#include "Farmer.h"

#include <iostream>
// Constructor
Farmer::Farmer()
    : money(50),
      pig(new Pig*[pigCount]),
      cow(new Cow*[cowCount]),
      wheat(new Wheat*[wheatCount]),
      corn(new Corn*[cornCount]),
      farmName(""),
      timesWheatPlanted(0),
      timesCornPlanted(0),
      timesCowsBought(0),
      timesPigsBought(0) {}

// sets the amount of money the farmer has.
void Farmer::setMoneyCount(int money) { this->money = money; }

// Returns the amount of money the farmer has.
int* Farmer::getMoneyCount() { return &money; }

// sets the farm name.
void Farmer::setFarmName() {
  bool validName = true;
  // if the name entered is valid, the program will continue. Otherwise the user
  // is prompted for another entry.
  while (validName) {
    // Asks user for the farm name and puts that into the variable farmName.
    cout << "What would you like to call your farm? (max 20 characters): "
         << endl;
    cin >> farmName;
    int i = 0;
    while (farmName[i] != '\0') {
      i++;
    }
    // checks if the farmName is less that 21 characters include the null
    // terminator. If not, outputs an error message and asks user to reenter the
    // farm name.
    if (i > 20) {
      cout << "Farm name is too long, please enter a shorter one." << endl;
    } else {
      validName = false;
    }
  }
}

// returns the farm name.
string Farmer::getFarmName() { return farmName; }

// returns the farm name, money, and the amount of pigs, cows, sheep, and wheat
// in the farm..
void Farmer::getStatus() {
  std::cout << "Hello " << getFarmName() << std::endl;
  std::cout << "Your bank account holds: " << *getMoneyCount() << " Dollars"
            << std::endl;
  std::cout << "You have " << cowCount << " cows" << std::endl;
  std::cout << "You have " << pigCount << " pigs" << std::endl;
  std::cout << "You have " << cornCount << " corns" << std::endl;
  std::cout << "You have " << wheatCount << " wheat" << std::endl;
  if (cowCount > 0) {
    cout << "Cow sell time: " << cow[0]->getSellTime() << " seconds" << endl;
  }
  if (pigCount > 0) {
    cout << "Pig sell time: " << pig[0]->getSellTime() << " seconds" << endl;
  }
  if (wheatCount > 0) {
    cout << "Wheat sell time: " << wheat[0]->getSellTime() << " seconds"
         << endl;
  }
  if (cornCount > 0) {
    cout << "Corn sell time: " << corn[0]->getSellTime() << " seconds" << endl;
  }
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

// creates a wheat object.
Wheat* Farmer::createNewWheat() {
  Wheat* newWheat = new Wheat;
  return newWheat;
}

// creates a corn object
Corn* Farmer::createNewCorn() {
  Corn* newCorn = new Corn;
  return newCorn;
}

// This function is used to buy pig and cow objects and put them into the pig or
// cow array.
void Farmer::buyAnimal() {
  // Asks user what animal they would like to buy and puts their response into
  // the product variables.
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

  // If the user types in cow, the code will prompt the user to type in how may
  // cows they would like to buy and puts this into the amount variable.
  if (getProduct() == "cow") {
    Cow tempCow;
    cout << "How many cows would you like to buy?, you can buy "
         << money / tempCow.getBuyPrice() << " cows" << endl;
    cin >> amount;
    while (amount < 0) {
      cout << "Invalid input please enter a positive value" << endl;
      cin >> amount;
    }
    // figure out how much the user has to pay.
    int amountPaid = tempCow.getBuyPrice() * amount;
    // Outputs message notifying user that they do not have enough money to buy
    // cows and asks user to enter a new amount.
    while (money < amountPaid) {
      cout << "You do not have enough money to buy " << amount << " cows"
           << endl;
      cout << "enter a new amount: ";
      cin >> amount;
      // Amount user has to pay to buy the cow.
      amountPaid = tempCow.getBuyPrice() * amount;
    }
    // decreasese the users money.
    money = money - amountPaid;
    // Initalises a new array that has enough space read in the cow objects
    // after the buying process.
    Cow** newCowArray = new Cow*[cowCount + amount];
    // Intialises the elements in the newCowArray to null pointers
    for (int i = 0; i < cowCount + amount; i++) {
      newCowArray[i] = nullptr;
    }
    // copies the current elements in cow into the newCowArray.
    for (int i = 0; i < cowCount; i++) {
      newCowArray[i] = cow[i];
    }
    // creates cow objects and adds them to the newCowArray.
    for (int i = cowCount; i < cowCount + amount; i++) {
      Cow* newCow = createNewCow();
      newCowArray[i] = newCow;
    }
    // deletes the cow array.
    delete[] cow;
    // The cow variable is now assigned to the newCowArray.
    cow = newCowArray;
    // sets cowCount.
    setCowCount(cowCount + amount);
    for (int i = 0; i < cowCount; i++) {
      cow[i]->Event(getCowCount());
    }
    // if the user enters pig, the code for buying pigs runs
  } else if (getProduct() == "pig") {
    Pig tempPig;
    // Message notifying user that they are buying pigs.
    cout << "How many pigs would you like to buy?, you can buy "
         << money / tempPig.getBuyPrice() << " pigs" << endl;
    cin >> amount;
    while (amount < 0) {
      cout << "Invalid input please enter a positive value" << endl;
      cin >> amount;
    }
    // Amount user has to pay to buy the pigs.
    int amountPaid = tempPig.getBuyPrice() * amount;
    // Notifies user that they do not have enough money to buy pigs and asks
    // them to enter an amount they can afford.
    while (money < amountPaid) {
      cout << "You do not have enough money to buy " << amount << " pigs"
           << endl;
      cout << "enter a new amount: ";
      cin >> amount;
      // Amount user has to pay to buy the pig.
      amountPaid = tempPig.getBuyPrice() * amount;
    }
    // decreasese the users money.
    money = money - amountPaid;
    // Initalises a new array that has enough space read in the pigs objects
    // after the buying process.
    Pig** newPigArray = new Pig*[pigCount + amount];
    // Intialises the elements in the newPigsArray to null pointers
    for (int i = 0; i < pigCount + amount; i++) {
      newPigArray[i] = nullptr;
    }
    // copies the current elements in pigs into the newPigArray.
    for (int i = 0; i < pigCount; i++) {
      newPigArray[i] = pig[i];
    }
    // creates pigs objects and adds them to the newPigArray.
    for (int i = pigCount; i < pigCount + amount; i++) {
      Pig* newPig = createNewPig();
      newPigArray[i] = newPig;
    }
    // Deletes the pig array.
    delete[] pig;
    // The pig variable is now assigned to the newPigArray.
    pig = newPigArray;
    // sets the pigCount.
    setPigCount(pigCount + amount);
    for (int i = 0; i < pigCount; i++) {
      pig[i]->Event(getPigCount());
    }
  }
}

// This function sells (deletes) the cow and pigs objects in the cow and wheat
// array.
void Farmer::sellAnimal() {
  // Asks the user what animal they would like to sell and puts their input to
  // the variable product.
  cout << "What animal would you like to sell, cow or pig? (Enter response in "
          "lower case)"
       << endl;
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
    // This for loop determines how many cow objects are ready to be sold and
    // increments readyToSellCount.
    for (int i = 0; i < cowCount; ++i) {
      if (currentTime - (cow[i]->getTimer()) >= cow[i]->getSellTime()) {
        newMoney = newMoney + cow[i]->getSellPrice();
        readyToSellCount++;
      }
    }
    // Initalises a new array that has enough space read in the cow objects
    // after the selling process.
    Cow** newCowArray = new Cow*[cowCount - readyToSellCount];
    // Message to confirm that the user wants to sell. Their response if read
    // into the optionChoice.
    cout << "you have " << readyToSellCount << " cows to sell for " << newMoney
         << " Would you like to sell them (enter Y or N)" << endl;
    cin >> optionChoice;
    // Asks user for a valid input if their previous input was invalid.
    while (optionChoice != "Y" && optionChoice != "N") {
      cout << "invalid input! please enter Y or N" << endl;
      cin >> optionChoice;
    }
    // If the user input Y, the selling process begins
    if (optionChoice == "Y") {
      for (int i = 0; i < cowCount; ++i) {
        //  This takes the cow objects in the cow array that are not ready to be
        //  sold and puts them into the the newCowArray.
        if ((currentTime - (cow[i]->getTimer())) < cow[i]->getSellTime()) {
          newCowArray[j] = cow[i];
          j++;
        } else {
          // if the objects are ready to be sold, that object in the wheat array
          // is deleted.
          delete cow[i];
        }
      }
      // increases the money that the farmer has.
      money = money + newMoney;
      // deletes the current cow array.
      delete[] cow;
      // The cow variable is now assigned to the newCowArray.
      cow = newCowArray;
      // sets thhe cowCount.
      setCowCount(cowCount - readyToSellCount);
    }
    if (optionChoice == "N") {
      cout << "No cow sold" << endl;
    }
    // If the user entered pig, the code to sell wheat will run.
  } else if (product == "pig") {
    string optionChoice;
    time_t currentTime = time(0);
    int j = 0;
    int readyToSellCount = 0;
    int newMoney = 0;
    // This for loop determines how many pig objects are ready to be sold and
    // increments readyToSellCount.
    for (int i = 0; i < pigCount; ++i) {
      if (currentTime - (pig[i]->getTimer()) >= pig[i]->getSellTime()) {
        newMoney = newMoney + pig[i]->getSellPrice();
        readyToSellCount++;
      }
    }
    // Initalises a new array that has enough space read in the pig objects
    // after the selling process.
    Pig** newPigArray = new Pig*[pigCount - readyToSellCount];
    // Message to confirm that the user wants to sell. Their response if read
    // into the optionChoice.
    cout << "you have " << readyToSellCount << " pigs to sell for " << newMoney
         << " Would you like to sell them (enter Y or N)" << endl;
    cin >> optionChoice;
    // Asks user for a valid input if their previous input was invalid.
    while (optionChoice != "Y" && optionChoice != "N") {
      cout << "invalid input! please enter Y or N" << endl;
      cin >> optionChoice;
    }
    // If the user input Y, the selling process begins
    if (optionChoice == "Y") {
      for (int i = 0; i < pigCount; ++i) {
        //  This takes the pig objects in the pig array that are not ready to be
        //  sold and puts them into the the newPigArray.
        if ((currentTime - (pig[i]->getTimer())) < pig[i]->getSellTime()) {
          newPigArray[j] = pig[i];
          j++;
        } else {
          // if the objects are ready to be sold, that object in the pig array
          // is deleted.
          delete pig[i];
        }
      }
      // increases the money the farmer has.
      money = money + newMoney;
      // deletes the current pig array.
      delete[] pig;
      // The pig variable is now assigned to the newPigArray.
      pig = newPigArray;
      // sets the pigCount
      setPigCount(pigCount - readyToSellCount);
    }

    if (optionChoice == "N") {
      cout << "No pig sold" << endl;
    }
  }
}

// This functions buys (creates and stores corn or wheat objects in the wheat or
// corn array)
void Farmer::buyCrop() {
  string newProduct;
  // Asks user what crop they want to buy and puts this into the newProduct
  // variables
  cout << "What crop would you like to buy? enter wheat or corn" << endl;
  cin >> newProduct;
  // sets the product variables
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
    cout << "How many wheat crops would you like to buy?, you can buy "
         << money / tempWheat.getBuyPrice() << " wheat" << endl;
    cin >> amount;
    while (amount < 0) {
      cout << "Invalid input please enter a positive value" << endl;
      cin >> amount;
    }
    // Amount user has to pay to buy the wheat
    int amountPaid = tempWheat.getBuyPrice() * amount;
    // Notifies user that they do not have enough money to buy wheat and asks
    // them to enter an amount they can afford.
    while (money < amountPaid) {
      cout << "You do not have enough money to buy " << amount << " wheat"
           << endl;
      cout << "enter a new amount: ";
      cin >> amount;
      // Amount user has to pay to buy the corn.
      amountPaid = tempWheat.getBuyPrice() * amount;
    }
    // decreasese the users money.
    money = money - amountPaid;

    // Initalises a new array that has enough space read in the wheat objects
    // after the buying process.
    Wheat** newWheatArray = new Wheat*[wheatCount + amount];
    // Intialises the elements in the newWheatArray to null pointers
    for (int i = 0; i < wheatCount + amount; i++) {
      newWheatArray[i] = nullptr;
    }
    // copies the current elements in wheat into the newWheatArray.
    for (int i = 0; i < wheatCount; i++) {
      newWheatArray[i] = wheat[i];
    }
    // creates wheat objects and adds them to the newWheatArray.
    for (int i = wheatCount; i < wheatCount + amount; i++) {
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
    for (int i = 0; i < wheatCount; i++) {
      wheat[i]->Event(getWheatCount());
    }
  } else if (getProduct() == "corn") {
    Corn tempCorn;
    // Message notifying user that they are buying corn.
    cout << "How many corn crops would you like to buy?, you can buy "
         << money / tempCorn.getBuyPrice() << " corn" << endl;
    cin >> amount;
    while (amount < 0) {
      cout << "Invalid input please enter a positive value" << endl;
      cin >> amount;
    }
    // Amount user has to pay to buy the corn.
    int amountPaid = tempCorn.getBuyPrice() * amount;
    // Notifies user that they do not have enough money to buy corn and asks
    // them to enter an amount they can afford.
    while (money < amountPaid) {
      cout << "You do not have enough money to buy " << amount << " corn"
           << endl;
      cout << "enter a new amount: ";
      cin >> amount;
      // Amount user has to pay to buy the corn.
      amountPaid = tempCorn.getBuyPrice() * amount;
    }
    // decreasese the users money.
    money = money - amountPaid;
    // Initalises a new array that has enough space read in the corn objects
    // after the buying process.
    Corn** newCornArray = new Corn*[cornCount + amount];
    // Intialises the elements in the newCornArray to null pointers
    for (int i = 0; i < cornCount + amount; i++) {
      newCornArray[i] = nullptr;
    }
    // copies the current elements in corn into the newCornArray.
    for (int i = 0; i < cornCount; i++) {
      newCornArray[i] = corn[i];
    }
    // creates corn objects and adds them to the newCornArray.
    for (int i = cornCount; i < cornCount + amount; i++) {
      Corn* newCorn = createNewCorn();
      newCornArray[i] = newCorn;
    }
    // deletes the corn array.
    delete[] corn;
    // The corn variable is now assigned to the newCornArray.
    corn = newCornArray;
    // sets the cornCount.
    setCornCount(cornCount + amount);
    for (int i = 0; i < cornCount; i++) {
      corn[i]->Event(getCornCount());
    }
  }
}

// returns the product variables.
string Farmer::getProduct() { return product; }

// sets the product variable.
void Farmer::setProduct(string product) { this->product = product; }

// This function sells (deletes) the corn and wheat objects in the corn and
// wheat array.
void Farmer::sellCrop() {
  // Asks the user what crop they would like to sell and puts their input to the
  // variable product.
  cout << "What crop would you like to sell, wheat or corn? (Enter response in "
          "lower case)"
       << endl;
  cin >> product;
  // Asks the user to enter a valid input.
  while (product != "wheat" && product != "corn") {
    cout << "invalid input! please enter wheat or corn" << endl;
    cin >> product;
  }
  // If the user entered wheat, the code to sell wheat will run.
  if (product == "wheat") {
    string optionChoice;
    time_t currentTime = time(0);
    int j = 0;
    int readyToSellCount = 0;
    int newMoney = 0;
    // This for loop determines how many wheat objects are ready to be sold and
    // increments readyToSellCount.
    for (int i = 0; i < wheatCount; ++i) {
      if (currentTime - (wheat[i]->getTimer()) >= wheat[i]->getSellTime()) {
        newMoney = newMoney + wheat[i]->getSellPrice();
        readyToSellCount++;
      }
    }
    // Initalises a new array that has enough space read in the wheat objects
    // after the selling process.
    Wheat** newWheatArray = new Wheat*[wheatCount - readyToSellCount];
    // Message to confirm that the user wants to sell. Their response if read
    // into the optionChoice.
    cout << "you have " << readyToSellCount << " wheat to sell for " << newMoney
         << " Would you like to sell them (enter Y or N)" << endl;
    cin >> optionChoice;
    // Asks user for a valid input if their previous input was invalid.
    while (optionChoice != "Y" && optionChoice != "N") {
      cout << "invalid input! please enter Y or N" << endl;
      cin >> optionChoice;
    }
    // If the user input Y, the selling process begins
    if (optionChoice == "Y") {
      for (int i = 0; i < wheatCount; ++i) {
        //  This takes the wheat objects in the wheat array that are not ready
        //  to be sold and puts them into the the newWheatArray.
        if ((currentTime - (wheat[i]->getTimer())) < wheat[i]->getSellTime()) {
          newWheatArray[j] = wheat[i];
          j++;
        } else {
          // if the objects are ready to be sold, that object in the wheat array
          // is deleted.
          delete wheat[i];
        }
      }
      // increases the money that the farmer has.
      money = money + newMoney;
      // deletes the current wheat array.
      delete[] wheat;
      // The pointer of wheat array will now point at the newWheat Array.
      wheat = newWheatArray;
      // sets the wheatCount
      setWheatCount(wheatCount - readyToSellCount);
    }

    if (optionChoice == "N") {
      cout << "No wheat sold" << endl;
    }
    // If the user entered corn, the code to sell wheat will run.
  } else if (getProduct() == "corn") {
    string optionChoice;
    time_t currentTime = time(0);
    int j = 0;
    int readyToSellCount = 0;
    int newMoney = 0;
    // This for loop determines how many corn objects are ready to be sold and
    // increments readyToSellCount.
    for (int i = 0; i < cornCount; ++i) {
      if (corn[i]->isReadyToSell() == true) {
        newMoney = newMoney + corn[i]->getSellPrice();
        readyToSellCount++;
      }
    }
    // Initalises a new array that has enough space read in the corn objects
    // after the selling process.
    Corn** newCornArray = new Corn*[cornCount - readyToSellCount];
    // Message to confirm that the user wants to sell. Their response if read
    // into the optionChoice.
    cout << "you have " << readyToSellCount << " corn to sell for " << newMoney
         << " Would you like to sell them (enter Y or N)" << endl;
    cin >> optionChoice;
    // Asks user for a valid input if their previous input was invalid.
    while (optionChoice != "Y" && optionChoice != "N") {
      cout << "invalid input! please enter Y or N" << endl;
      cin >> optionChoice;
    }
    // If the user input Y, the selling process begins
    if (optionChoice == "Y") {
      for (int i = 0; i < wheatCount; ++i) {
        //  This takes the corn objects in the corn array that are not ready to
        //  be sold and puts them into the the newCornArray.
        if ((currentTime - (corn[i]->getTimer())) < corn[i]->getSellTime()) {
          newCornArray[j] = corn[i];
          j++;
        } else {
          // if the objects are ready to be sold, that object in the corn array
          // is deleted.
          delete corn[i];
        }
      }
      // increases the money that the farmer has.
      money = money + newMoney;
      // deletes the current corn array.
      delete[] corn;
      // The pointer of corn array will now point at the newCornArray.
      corn = newCornArray;
      // sets the cornCount.
      setCornCount(cornCount - readyToSellCount);
    }

    if (optionChoice == "N") {
      cout << "No corn sold" << endl;
    }
  }
}

// setter for cowCount
void Farmer::setCowCount(int cowCount) { this->cowCount = cowCount; }

// setter for pigCount
void Farmer::setPigCount(int pigCount) { this->pigCount = pigCount; }

// setter for wheatCount
void Farmer::setWheatCount(int wheatCount) { this->wheatCount = wheatCount; }

// setter for cornCount
void Farmer::setCornCount(int cornCount) { this->cornCount = cornCount; }

// return the address of the cowCount.
int* Farmer::getCowCount() { return &cowCount; }

// return the address of the pigCount.
int* Farmer::getPigCount() { return &pigCount; }

// return the address of the wheatCount.
int* Farmer::getWheatCount() { return &wheatCount; }

// return the address of the cornCount.
int* Farmer::getCornCount() { return &cornCount; }

// returns a double pointer to the first element of the cow array.
Cow** Farmer::getCowArray() { return cow; }

// returns a double pointer to the first element of the pig array.
Pig** Farmer::getPigArray() { return pig; }

// returns a double pointer to the first element of the wheat array.
Wheat** Farmer::getWheatArray() { return wheat; }

// returns a double pointer to the first element of the corn array.
Corn** Farmer::getCornArray() { return corn; }

void Farmer::applySpeedGrowAnimals() {
  string product;

  Wheat functionWheat;
  Corn functionCorn;
  Pig functionPig;
  Cow functionCow;

  cout << "What crop would you like to upgrade? cow or pig? (Enter response in "
          "lower case)"
       << endl;
  cin >> product;  // reading user input

  while (product != "pig" &&
         product != "cow") {  // validating user input, rerequesting if invalid
    cout << "invalid input! please enter cow or pig" << endl;
    cin >> product;  // reading user input
  }

  if (product == "cow" && *getCowCount() == 0) {
    cout << "You have no cows, please buy some cows before applying speedGrow"
         << endl;  // prompting user to buy cows before applying speedgrow
    return;
  }

  if (product == "pig" && *getPigCount() == 0) {
    cout << "You have no pigs, please buy some cows before applying speedGrow"
         << endl;  // prompting user to buy pigs before applying speedgrow
    return;
  }

  if (product == "pig") {
    int option;
    int newMoney = 0;

    int numberCanUpgrade =
        money / functionPig.getSpeedGrowPrice();  // calculating number of
                                                  // upgrades player can pay for

    if (numberCanUpgrade > pigCount) {  // limiting this number to the number of
                                        // pigs the player has
      numberCanUpgrade = pigCount;
    }

    int optionChoice = 0;
    cout << "You can upgrade " << numberCanUpgrade << " pigs" << endl;
    cout << "Enter the number that you would like to upgrade or 0 to exit"
         << endl;
    cin >> optionChoice;  // reading user input
    while (
        cin.fail() || optionChoice < 0 ||
        optionChoice >
            numberCanUpgrade) {  // validating input and rerequesting if
                                 // invalid, reference(cin.fail() method):
                                 // https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/
      cout << "invalid input! please enter a valid number" << endl;
      cin.clear();  // clearing error flags from the input stream
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');     // ignoring the rest of the line
      cin >> optionChoice;  // reading user input
    }
    if (optionChoice != 0) {
      int j = 0;
      for (int i = 0; i < pigCount; ++i) {  // iterating though pig array
        if (j < optionChoice) {  // executing applySpeedGrowth only the number
                                 // of times requested by the player
          pig[i]->applySpeedGrowth(&money);
          j++;
        } else {
          break;
        }
      }
    }

  } else if (product == "cow") {
    int option;
    int newMoney = 0;

    int numberCanUpgrade =
        money /
        functionCow.getSpeedGrowPrice();  // calculating the number of upgrades
                                          // the player can play for

    if (numberCanUpgrade >
        cowCount) {  // limiting this number to the numbe of cows the player has
      numberCanUpgrade = cowCount;
    }

    int optionChoice = 0;
    cout << "You can upgrade " << numberCanUpgrade << " cows" << endl;
    cout << "Enter the number that you would like to upgrade or 0 to exit"
         << endl;
    cin >> optionChoice;  // reading user input
    while (
        cin.fail() || optionChoice < 0 ||
        optionChoice >
            numberCanUpgrade) {  // validating input and rerequesting if
                                 // invalid, reference(cin.fail() method):
                                 // https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/
      cout << "invalid input! please enter a valid number" << endl;
      cin.clear();  // clearing error flags from the input stream
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');     // ignoring the rest of the line
      cin >> optionChoice;  // reading user input
    }
    if (optionChoice != 0) {
      int j = 0;
      for (int i = 0; i < cowCount; ++i) {  // iterating through the cow array
        if (j < optionChoice) {  // executing applySpeedGrowth only the number
                                 // of times requested by the user
          cow[i]->applySpeedGrowth(&money);
          j++;
        } else {
          break;
        }
      }
    }
  }
  cout << "Speed growth for barn successfully applied. " << endl;
}

void Farmer::applyHighYieldAnimals() {
  string product;

  // temporary objects within function to get default variable values

  Wheat functionWheat;
  Corn functionCorn;
  Pig functionPig;
  Cow functionCow;

  cout << "What crop would you like to upgrade? cow or pig? (Enter response in "
          "lower case)"
       << endl;
  cin >> product;  // reading user input

  while (product != "pig" &&
         product != "cow") {  // validating user input, rerequesting if invalid
    cout << "invalid input! please enter cow or pig" << endl;
    cin >> product;  // reading user input
  }

  if (product == "cow" && *getCowCount() == 0) {
    cout << "You have no cows, please buy some cows before applying highYield"
         << endl;  // prompting user to buy cows before applying highyield
    return;
  }

  if (product == "pig" && *getPigCount() == 0) {
    cout << "You have no pigs, please buy some pigs before applying highYield"
         << endl;  // prompting user to buy pigs before applying highyield
    return;
  }

  if (product == "pig") {
    int option;
    int newMoney = 0;

    int numberCanUpgrade =
        money /
        functionPig.getHighYieldPrice();  // calculating the number of upgrades
                                          // the player can pay for

    if (numberCanUpgrade >
        pigCount) {  // limiting this number to the number of pigs the playe has
      numberCanUpgrade = pigCount;
    }

    int numberUpgraded = 0;
    cout << "You can upgrade " << numberCanUpgrade << " pigs" << endl;
    cout << "Enter the number that you would like to upgrade or 0 to exit"
         << endl;
    cin >> numberUpgraded;  // reading user input
    while (
        cin.fail() || numberUpgraded < 0 ||
        numberUpgraded >
            numberCanUpgrade) {  // validating input and rerequesting if
                                 // invalid, reference(cin.fail() method):
                                 // https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/
      cout << "invalid input! please enter a valid number" << endl;
      cin.clear();  // clearing error flags from the input stream
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');       // ignoring the rest of the line
      cin >> numberUpgraded;  // reading user input
    }
    if (numberUpgraded != 0) {
      int j = 0;
      for (int i = 0; i < pigCount; ++i) {  // iterating through the pig array
        if (j < numberUpgraded) {
          pig[i]->applyHighYield(
              &money);  // executing applyHighYield only the numbe ro times
                        // requested by the player
          j++;
        } else {
          break;
        }
      }
    }

  } else if (product == "cow") {
    int option;
    int newMoney = 0;

    int numberCanUpgrade =
        money /
        functionCow.getHighYieldPrice();  // calculating the number of upgrades
                                          // the player can pay for

    if (numberCanUpgrade > cowCount) {  // limiting this number to the number of
                                        // cows the player has
      numberCanUpgrade = cowCount;
    }

    int numberUpgraded = 0;
    cout << "You can upgrade " << numberCanUpgrade << " cows" << endl;
    cout << "Enter the number that you would like to upgrade or 0 to exit"
         << endl;
    cin >> numberUpgraded;  // reading user input
    while (
        cin.fail() || numberUpgraded < 0 ||
        numberUpgraded >
            numberCanUpgrade) {  // validating input and rerequesting if
                                 // invalid, reference(cin.fail() method):
                                 // https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/
      cout << "invalid input! please enter a valid number" << endl;
      cin.clear();  // clearing error flags from the input stream
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');       // ignoring the rest of the line
      cin >> numberUpgraded;  // reading user input
    }
    if (numberUpgraded != 0) {
      int j = 0;
      for (int i = 0; i < cowCount; ++i) {  // iteratig through the cow array
        if (j < numberUpgraded) {  // executing apply highHighYield only the
                                   // number of times requested by the user
          cow[i]->applyHighYield(&money);
          j++;
        } else {
          break;
        }
      }
    }
  }
  cout << "HighYield successfully applied" << endl;
}

void Farmer::applySpeedGrowCrops() {
  string product;

  // initializing the temporary objects to get default variable values

  Wheat functionWheat;
  Corn functionCorn;
  Pig functionPig;
  Cow functionCow;

  cout << "What crop would you like to upgrade? wheat or corn? (Enter response "
          "in lower case)"
       << endl;
  cin >> product;

  while (product != "wheat" &&
         product !=
             "corn") {  // validating user input and rerequesting if invalid
    cout << "invalid input! please enter wheat or corn" << endl;
    cin >> product;
  }

  if (product == "corn" && *getCornCount() == 0) {
    cout << "You have no corn, please buy some corn before applying speedGrow"
         << endl;  // let user know that they need to buy some corn before
                   // applying speedGrow
    return;
  }

  if (product == "wheat" && *getWheatCount() == 0) {
    cout << "You have no wheat, please buy some corn before applying speedGrow"
         << endl;  // let user know that they need to buy some wheat before
                   // applying speedGrow
    return;
  }

  if (product == "wheat") {
    int option;
    int newMoney = 0;

    int numberCanUpgrade =
        money /
        functionWheat.getSpeedGrowPrice();  // calculating the number of inputs
                                            // the player can pay for

    if (numberCanUpgrade > wheatCount) {  // limiting this number to the number
                                          // of wheat the player had
      numberCanUpgrade = wheatCount;
    }

    int optionChoice = 0;
    cout << "You can upgrade " << numberCanUpgrade << " wheat" << endl;
    cout << "Enter the number that you would like to upgrade or 0 to exit"
         << endl;
    cin >> optionChoice;  // reading user input
    while (
        cin.fail() || optionChoice < 0 ||
        optionChoice >
            numberCanUpgrade) {  // validating input and rerequesting if
                                 // invalid, reference(cin.fail() method):
                                 // https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/
      cout << "invalid input! please enter a valid number" << endl;
      cin.clear();  // clearing error flags from the input stream
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');     // ignoring the rest of the line
      cin >> optionChoice;  // reading user input
    }
    if (optionChoice != 0) {
      int j = 0;
      for (int i = 0; i < wheatCount;
           ++i) {                // iterating through the wheat array
        if (j < optionChoice) {  // executing applySpeedGrowth only the number
                                 // of times requested by the user
          wheat[i]->applySpeedGrowth(&money);
          j++;
        } else {
          break;
        }
      }
    }
  } else if (product == "corn") {
    int option;
    int newMoney = 0;

    int numberCanUpgrade =
        money /
        functionCorn.getSpeedGrowPrice();  // calculating the number of upgrades
                                           // the player can pay for

    if (numberCanUpgrade > cornCount) {  // limiting this number to the number
                                         // of corn the player has
      numberCanUpgrade = cornCount;
    }

    int optionChoice = 0;
    cout << "You can upgrade " << numberCanUpgrade << " corn" << endl;
    cout << "Enter the number that you would like to upgrade or 0 to exit"
         << endl;
    cin >> optionChoice;  // reading user input
    while (
        cin.fail() || optionChoice < 0 ||
        optionChoice >
            numberCanUpgrade) {  // validating input and rerequesting if
                                 // invalid, reference(cin.fail() method):
                                 // https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/
      cout << "invalid input! please enter a valid number" << endl;
      cin.clear();  // clearing error flags from the input stream
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');     // ignoring the rest of the line
      cin >> optionChoice;  // reading user input
    }
    if (optionChoice != 0) {
      int j = 0;
      for (int i = 0; i < cornCount; ++i) {  // iterating through the corn array
        if (j < optionChoice) {  // executing applySpeedGrowth only the number
                                 // of times requested by the user
          corn[i]->applySpeedGrowth(&money);
          j++;
        } else {
          break;
        }
      }
    }
  }
  cout << "speedGrowth for field successfully applied" << endl;
}

void Farmer::applyHighYieldCrops() {
  string product;

  // temporary objects to get default variable values

  Wheat functionWheat;
  Corn functionCorn;
  Pig functionPig;
  Cow functionCow;

  cout << "What crop would you like to upgrade? wheat or corn? (Enter response "
          "in lower case)"
       << endl;
  cin >> product;

  while (product != "wheat" &&
         product != "corn") {  // validating input and rerequesting if invalid
    cout << "invalid input! please enter wheat or corn" << endl;
    cin >> product;
  }

  if (product == "corn" && *getCornCount() == 0) {
    cout << "You have no corn, please buy corn to apply the upgrade"
         << endl;  // let user know that they need to buy some corn before
                   // applying highyield
    return;
  }

  if (product == "wheat" && *getWheatCount() == 0) {
    cout << "You have no wheat, please buy wheat to apply the upgrade"
         << endl;  // let user know that they need to buy some wheat before
                   // applying highyield
    return;
  }

  if (product == "wheat") {
    int option;
    int newMoney = 0;

    int numberCanUpgrade =
        money /
        functionWheat.getHighYieldPrice();  // calculating the number of
                                            // upgrades the player can pay for

    if (numberCanUpgrade > wheatCount) {  // limiting this number to the number
                                          // of wheat the player has
      numberCanUpgrade = wheatCount;
    }

    int optionChoice = 0;
    cout << "You can upgrade " << numberCanUpgrade << " wheat" << endl;
    cout << "Enter the number that you would like to upgrade or 0 to exit"
         << endl;
    cin >> optionChoice;  // reading user input
    while (
        cin.fail() || optionChoice < 0 ||
        optionChoice >
            numberCanUpgrade) {  // validating input and rerequesting if
                                 // invalid, reference(cin.fail() method):
                                 // https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/
      cout << "invalid input! please enter a valid number" << endl;
      cin.clear();  // clearing error flags from the input stream
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');     // ignoring the rest of the line
      cin >> optionChoice;  // reading user input
    }
    if (optionChoice != 0) {
      int j = 0;
      for (int i = 0; i < wheatCount;
           ++i) {                // iterating through the wheat array
        if (j < optionChoice) {  // executing applyHigh Yield only the number of
                                 // times requested by the player
          wheat[i]->applyHighYield(&money);
          j++;
        } else {
          break;
        }
      }
    }
  } else if (product == "corn") {
    int option;
    int newMoney = 0;

    int numberCanUpgrade =
        money /
        functionCorn.getHighYieldPrice();  // calculating how many upgrades the
                                           // player can pay for

    if (numberCanUpgrade >
        cornCount) {  // limiting the number of available upgrades to the number
                      // of corn player has
      numberCanUpgrade = cornCount;
    }

    int optionChoice = 0;
    cout << "You can upgrade " << numberCanUpgrade << " corn" << endl;
    cout << "Enter the number that you would like to upgrade or 0 to exit"
         << endl;
    cin >> optionChoice;
    while (
        cin.fail() || optionChoice < 0 ||
        optionChoice >
            numberCanUpgrade) {  // validating input and rerequesting if
                                 // invalid, reference(cin.fail() method):
                                 // https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/
      cout << "invalid input! please enter a valid number" << endl;
      cin.clear();  // clear error flags on input stream
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');  // ignore the rest of the line
      cin >> optionChoice;
    }
    if (optionChoice != 0) {  // executing loop only if player has decided to
                              // upgrade (i.e chooses value above 0)
      int j = 0;
      for (int i = 0; i < cornCount; ++i) {  // iterating though corn array
        if (j < optionChoice) {  // executing applyHighYield only the number of
                                 // times the player has chosen
          corn[i]->applyHighYield(&money);
          j++;
        } else {
          break;
        }
      }
    }
  }
  cout << "HighYield successfully applied" << endl;
}

void Farmer::executeEvent() {
  if (getProduct() == "cow") {
    if (cow[9]->getCowEvent() == true &&
        *getCowCount() >
            9) {  // statement to check if event should be executed or not
      cout << "A disease has spread throughout the cows, half of your cows "
              "have died."
           << endl;
      int newCowCount = cowCount * 0.5;  // half the cow count
      for (int i = newCowCount; i < cowCount;
           i++) {  // loop to shift every element in array to the first half of
                   // the array
        cow[i - newCowCount] = cow[i];
        cow[i]->setCowEvent(false);
      }
      cowCount = newCowCount;  // decrease cow count to finish array
    }
  }
  if (getProduct() == "pig") {
    if (pig[9]->getPigEvent() == true &&
        *getPigCount() >
            9) {  // statement to check if event should be executed or not
      cout << "the demand for pig meat greatly decreased, in order to maintain "
              "a healthy flow of pigs "
           << endl;
      cout << "coming in and out of the farm, the sell price of all currently "
              "owned pigs must be reduced by half."
           << endl;
      for (int i = 0; i < pigCount; i++) {
        pig[i]->setSellPrice(
            (pig[i]->getSellPrice()) *
            0.5);  // decrease the sell pricec for each pig by half
        pig[i]->setPigEvent(false);
      }
    }
  }
  if (getProduct() == "wheat") {
    if (wheat[9]->getWheatEvent() == true && *getWheatCount() > 9) {
      int newWheatCount = 0;
      if (wheat[9]->getPesticideApplied() == true) {
        // a similar implementation used in the cow event is used for this
        // event,
        // the difference is that the arary is 1/4 the orignal size compared to
        // the cow event where the array size was halved
        cout << "A disease has spread throughout the wheat, 1/4 of your wheat "
                "have died."
             << endl;
        newWheatCount = (wheatCount) * 0.25;
        cout << "Your pesticide has been used" << endl;
        for (int i = newWheatCount; i < wheatCount; i++) {
          wheat[i - newWheatCount] = wheat[i];
          wheat[i]->setWheatEvent(false);
          wheat[i]->setPesticideApplied(false);
        }
        wheatCount = newWheatCount;
      }

      if (wheat[9]->getPesticideApplied() == false) {
        // only redcucing the wheat array by half if pesticide is applied
        cout << "A disease has spread throughout the wheat, half of your wheat "
                "have died."
             << endl;
        newWheatCount = (wheatCount) * 0.5;
        for (int i = newWheatCount; i < wheatCount; i++) {
          wheat[i - newWheatCount] = wheat[i];
          wheat[i]->setWheatEvent(
              false);  // re-setting the wheat event to false so that the event
                       // doesnt run again
        }
        wheatCount = newWheatCount;
      }
    }
  }
  if (getProduct() == "corn") {
    if (corn[9]->getCornEvent() == true && *getCornCount() > 9) {
      if (corn[9]->getPesticideApplied() == true) {
        // the corn event is the same as the wheat event
        cout << "A disease has spread throughout the corn, 1/4 of your corn "
                "have died."
             << endl;
        int newCornCount = (cornCount) * 0.25;
        cout << "Your Pesticide has been used" << endl;
        for (int i = newCornCount; i < cornCount; i++) {
          corn[i - newCornCount] = corn[i];
          corn[i]->setCornEvent(false);
          corn[i]->setPesticideApplied(false);
        }
        cornCount = newCornCount;
      }

      if (corn[9]->getPesticideApplied() == false) {
        // identical implementation to the wheat event
        cout << "A disease has spread throughout the wheat, half of your wheat "
                "have died."
             << endl;
        int newCornCount = (cornCount) * 0.5;
        for (int i = newCornCount; i < cornCount; i++) {
          corn[i - newCornCount] = corn[i];
          corn[i]->setCornEvent(false);
        }
        cornCount = newCornCount;
      }
    }
  }
}

void Farmer::appliedPesticide() {
  Corn tempCorn;
  Wheat tempWheat;
  // initialise the pesticideChoice variable.
  string pesticideChoice = "";
  // asks user if they want to buy pesticide.
  cout << " Do you want to buy pesticide Y or N" << endl;
  cin >> pesticideChoice;
  // If the user does not enter a valid input, code will prompt user to enter it
  // again.
  while (pesticideChoice != "Y" && pesticideChoice != "N") {
    cout << " Invalid input, enter either Y or N" << endl;
    cin >> pesticideChoice;
  }
  // initialise product variable.
  string product = "";
  // Asks user if they want to buy pesticide and puts it into product.
  cout << " Do you want to buy pesticide for corn or wheat" << endl;
  cin >> product;
  // asks user for another input if their previous input is invalid.
  while (product != "corn" && product != "wheat") {
    cout << " Invalid input, enter either corn or wheat" << endl;
    cin >> product;
  }

  if (pesticideChoice == "Y") {
    if (product == "corn") {
      if (*getCornCount() > 0) {
        // runs below code if the user wants to buy pesticde for corn and corn
        // count is greater than 0. intialise numCornPesticideApplied to 0.
        int numCornPesticideApplied = 0;
        // checks which corn objects do not have pesticide applied.
        for (int i = 0; i < *getCornCount(); i++) {
          if (corn[i]->getPesticideApplied() == false) {
            // increments numCornPesticideApplied if the corn object does not
            // have pestiicide.
            numCornPesticideApplied++;
          }
        }

        // Inform the user of the number of corn crops without pesticide applied
        // and the total cost to apply it.
        cout << " You have " << numCornPesticideApplied
             << " corn with no pesticide applied it will cost "
             << numCornPesticideApplied * tempCorn.getPesticidePrice();
        // Prompt the user to decide whether to purchase pesticide.
        cout << " do you want to buy pesticide, enter Y or N" << endl;
        cin >> pesticideChoice;
        // Validate the user's input, ensuring it's either 'Y' or 'N'.
        while (pesticideChoice != "Y" && pesticideChoice != "N") {
          cout << " Invalid input, enter either Y or N" << endl;
          cin >> pesticideChoice;
        }

        // If the user chooses to buy pesticide for corn, the code below runs.
        if (pesticideChoice == "Y") {
          // Loop through each corn crop.
          for (int i = 0; i < *getCornCount(); i++) {
            // Check if there's enough money to apply pesticide to all
            // applicable crops
            if (*getMoneyCount() <
                numCornPesticideApplied * tempCorn.getPesticidePrice()) {
              cout << " You do not have enough money, try again later" << endl;
              break;
            }
            // Apply pesticide to corn crops that currently do not have it.
            if (corn[i]->getPesticideApplied() == false) {
              corn[i]->setPesticideApplied(true);
            }
          }
        }
      } else {
        // Inform the user if there are no corn crops.
        cout << " You have no corn" << endl;
      }
    }
  }

  // Check if the user has chosen to buy pesticide for wheat.
  if (pesticideChoice == "Y") {
    // If the product is wheat the code below runs.
    if (product == "wheat") {
      // Ensure there is wheat to apply pesticide to.
      if (*getWheatCount() > 0) {
        // Count wheat crops without pesticide applied.
        int numWheatPesticideApplied = 0;
        for (int i = 0; i < *getWheatCount(); i++) {
          if (wheat[i]->getPesticideApplied() == false) {
            numWheatPesticideApplied++;
          }
        }
        // Inform the user of the number of untreated wheat crops and total
        // pesticide cost.
        cout << " You have " << numWheatPesticideApplied
             << " corn with no pesticide applied it will cost "
             << numWheatPesticideApplied * tempCorn.getPesticidePrice();
        // Prompt the user to decide whether to buy pesticide for wheat.
        cout << " do you want to buy pesticide, enter Y or N" << endl;
        cin >> pesticideChoice;
        // Validate the user's input for wheat.
        while (pesticideChoice != "Y" && pesticideChoice != "N") {
          cout << " Invalid input, enter either Y or N" << endl;
          cin >> pesticideChoice;
        }

        // If the user decides to buy pesticide for wheat the code below runs.
        if (pesticideChoice == "Y") {
          for (int i = 0; i < *getWheatCount(); i++) {
            // Check if there's enough money to apply pesticide to all
            // applicable wheat crops.
            if (*getMoneyCount() <
                numWheatPesticideApplied * tempWheat.getPesticidePrice()) {
              cout << " You do not have enough money, try again later" << endl;
              break;
            }
            // Apply pesticide to wheat crops that currently do not have it.
            if (wheat[i]->getPesticideApplied() == false) {
              wheat[i]->setPesticideApplied(true);
            }
          }
        }
      } else {
        // Inform the user if there are no wheat crops.
        cout << " You have no wheat" << endl;
      }
    }
  }
  // If the user chose not to buy pesticide, outputs a message.
  if (pesticideChoice == "N") {
    cout << " You have chosen not to buy pesticide" << endl;
  }
}

// the read and write files were written using information from the week 5
// lecture video
void Farmer::fileReader(string filename) {
  // open the file
  inputFile.open(filename, ios::in);
  // read in the integer value in the file
  int newMoney;
  inputFile >> newMoney;
  // close the file
  inputFile.close();
  // set the money count to the value from the file
  setMoneyCount(newMoney);
}

void Farmer::fileWriter(string filename, int* money) {
  // open the output file which will be the same as the input file for
  // simplicity
  outputFile.open(filename, ios::out);
  // write the money parameter into the txt file
  outputFile << *money << endl;
  // close the file
  outputFile.close();
}

Farmer::~Farmer() {
  // the if statments are implemented to prevent epmty arrays being deleted, as
  // this would result in an segmentation fault
  if (*getCowCount() > 0) {
    for (int i = 0; i < cowCount; i++) {
      cow[i] = nullptr;  // set every element in array to null pointer
    }
    delete[] cow;  // delete the array
  }
  // the following code uses identical implementation as the above destructor
  // for the cow array
  if (*getPigCount() > 0) {
    for (int i = 0; i < pigCount; i++) {
      pig[i] = nullptr;
    }
    delete[] pig;
  }
  if (*getWheatCount() > 0) {
    for (int i = 0; i < wheatCount; i++) {
      wheat[i] = nullptr;
    }
    delete[] wheat;
  }
  if (*getCornCount() > 0) {
    for (int i = 0; i < cornCount; i++) {
      corn[i] = nullptr;
    }
    delete[] corn;
  }
}