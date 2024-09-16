#include "Field.h"

void Field::Fertilzation(){
    //Bank account - Fertilization Price.
}
void Field::Pesticide(){
    //Bank account - Pesticide Price.
}
void Field:: setPrice(){
    FertilizationPrice = 90;
    PesticidePrice = 80;
}
int Field:: getPrice(){
    std:: cout << "Fertilzer Price is: " << FertilizationPrice << "Pesticide Price is: " << PesticidePrice << std::endl;
}

int Field::maxFieldCapacity(){}
int Field::increaseMaxFieldCapacity(){}
int Field::getMaxFieldCapacity(){}