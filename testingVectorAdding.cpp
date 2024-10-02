#include <iostream>

class Field{

int fieldNumber;
bool isPlanted();
time_t timer;

Field(int fieldNUmber);

};

class cowPaddocks{

    Field** Field[3];
    int unlockedFields();
    void giveStatus(); //only displays unlocked fields
    void plantField(); // isPlanted == true & money deducted & timer initializd
    void harvestField(); // isPlanted == false & money added

};

int main(){

    Field f1(1);
    Field f2(2);
    Field f3(3);

}


