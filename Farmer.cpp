#include "Farmer.h"

#include <iostream>
#include <string>

using namespace std;

void Farmer::setFarmName() {
    cout << "what would you like to call your farm (max 20 characters): " << endl;
    cin >> FarmName;
    int i = 0;
    while (FarmName[i] != '\0'){
        i++;
    }
    if (i > 20){
        cout << "Farm name is too long, enter a shorter one" << endl;
    }

}
string Farmer::getFarmName() {
    return FarmName;
}

int Farmer::getDayCount() {
    return DayCount;
}