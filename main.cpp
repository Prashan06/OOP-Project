#include <iostream>
#include <string>

#include "Farmer.h"
#include "Farm.h"
#include "Field.h"
#include "Barn.h"
#include "Cow.h"
#include "Pig.h"
#include "Wheat.h"
#include "Corn.h"
#include "Events.h"

using namespace std;

// main file that will define the method for the player to play the game

int main(){
    // initialising global variables to be used throughout the course of the game 
    Farmer farmer;
    bool mainScreen = true;
    bool barnScreen, fieldScreen = false;

    farmer.setFarmName();

    while (mainScreen = true){
        string optionChoice;
        cout << "Hello " << farmer.getFarmName() << "!" << endl;
        cout << "what action would you like to take?" << endl;
        cout << "view status, enter status" << endl;
        cout << "visit the barn, enter barn" << endl;
        cout << "visit the field, enter field" << endl;
        cin >> optionChoice;
        if (optionChoice == "status") {
            farmer.getStatus();
        } else if (optionChoice == "barn") {
            barnScreen = true;
            mainScreen = false;
        } else if (optionChoice == "field"){
            fieldScreen = true;
            mainScreen = false;
        }
        
    }

    while (barnScreen == true) {

    }

    while (fieldScreen == true) {

    }

    return 0;
    
}