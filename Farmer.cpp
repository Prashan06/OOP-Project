#include <iostream>
#include <ctime>
#include "Farmer.h"

using namespace std;


Farmer:: Farmer() : Money(50), DayLength(60), startTime(std::time(nullptr)), FarmName(""){}

int Farmer::nextDay() {
    time_t currentTime = std::time(nullptr);
    int timer = difftime(startTime, currentTime);
    if (timer % DayLength == 0) {
        cout << "A new day has begun!" << endl;
        DayCount++;
        Money = Money + 50;
    }
    return timer;
}


int Farmer:: getMoneyCount(){
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

int Farmer::getDayLength() {
    return DayLength;
}