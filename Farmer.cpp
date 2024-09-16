#include "Farmer.h"

using namespace std;

Farmer:: Farmer() : Money(100), DayLength(60), time(time_t(NULL)-time_t(0)), FarmName(""){
    if (time % DayLength == 0) {
        DayCount++;
    }
}


float Farmer:: getMoneyCount(){
    return Money;
}
void Farmer:: setMoneyCount(int Money){
    this -> Money = Money;
}

void Farmer:: getStatus(){
    std::cout << "Hello " << getFarmName() << std::endl;
    std::cout << "Your bank account holds: " << getMoneyCount() << " Dollars" << std::endl;
    std::cout << "The current day is: " << getDayCount() << std::endl;
}


void Farmer::setFarmName() {
    bool validName = true;
    while (validName) {
        cout << "what would you like to call your farm (max 20 characters): " << endl;
        cin >> FarmName;
        int i = 0;
        while (FarmName[i] != '\0'){
            i++;
        }
        if (i > 20){
            cout << "Farm name is too long, enter a shorter one" << endl;
        } else {
            validName = false;
        }
        
    }
}
string Farmer::getFarmName() {
    return FarmName;
}

int Farmer::getDayCount() {
    return DayCount;
}