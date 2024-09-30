#include "Farmer.h"

// Constructor 
Farmer:: Farmer() : money(50),pig(0),cow(0),wheat(0),corn(0),farmName(""),cropCount(0),animalCount(0) {}
// Returns the amount of money the farmer has.
int Farmer:: getMoneyCount(){
    return money;
}
// sets the amount of money the farmer has.
void Farmer:: setMoneyCount(int money){
    this -> money = money;
}
// returns the farm name and money.
void Farmer:: getStatus(){
    std::cout << "Hello " << getFarmName() << std::endl;
    std::cout << "Your bank account holds: " << getMoneyCount() << " Dollars" << std::endl;
}
// sets the farm name.
void Farmer::setFarmName() {
    bool validName = true;
    // if the name entered is valid, the program will continue, otherwise the user is prompted for another entry.
    while (validName) {
        cout << "what would you like to call your farm (max 20 characters): " << endl;
        cin >> farmName;
        int i = 0;
        while (farmName[i] != '\0'){
            i++;
        }
        if (i > 20){
            cout << "Farm name is too long, enter a shorter one" << endl;
        } else {
            validName = false;
        }
    }
}
//returns the farm name.
string Farmer::getFarmName() {
    return farmName;
}
void Farmer:: buyItem(){
    char product;
    cout << "What animal or crop would you like to sell? Enter response in lower case " << endl;
    cin >> product;
    switch (product) {
        case 'cow' :
        farm.setBuyPrice(10);
        
        case 'pig':
        case 'corn':
        case 'wheat': 
    }
}
void Farmer:: sellItem(){
}
int Farmer:: getCropCount(){
    return cropCount;
}
// Sets the number of wheat and corn in the farm
void Farmer:: setCropCount(){
    this->cropCount = wheat.size() + corn.size();
}
// returns the number of pig and cows currently in the farm
int Farmer::getAnimalCount(){
    return animalCount;
}
void Farmer::setAnimalCount (){
    this-> animalCount = pig.size() + cow.size();
}