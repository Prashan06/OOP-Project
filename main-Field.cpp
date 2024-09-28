#include "Field.h"
#include <iostream>

/* This file will test the functions in the Field class, this file will not test any functions or data members that teh field class inherits*/

int main(){
    Field f;
    f.setCropCount(10,10); //realistic case, sets cropcount to 20
    std::cout<< "Crop count is: "<< f.getCropCount() << std::endl;
    f.setCropCount(1000000,20000); //boundry case, sets cropcount to 1020000.
    std::cout << "Crop count is: " << f.getCropCount() << std::endl;
    f.Fertilisation();
    return 0;
}