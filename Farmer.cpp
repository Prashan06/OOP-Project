#include "Farmer.h"

Farmer:: Farmer() : Money(0), DayLength(0), DayCount(0), time(0), FarmName(""){}

Farmer :: Farmer() : Money(Money), DayLength(60), DayCount(0), time(0), FarmName(""){

}

float Farmer:: getMoneyCount(){
    return Money;
}
void Farmer:: setMoneyCount(){
    this -> Money = Money;
}

void Farmer:: getStatus(){
    std::cout << "Hello " << getFarmName() << std::endl;
    std::cout << "Your bank account holds: " << getMoneyCount() << " Dollars" << std::endl;
    std::cout << "The current day is: " << getDayCount() << std::endl;
}

void Farmer::setFarmName(){

}
std::string Farmer::getFarmName(){

}