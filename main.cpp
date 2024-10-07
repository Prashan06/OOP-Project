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
    string optionChoice;

    farmer.setFarmName();

    while (mainScreen = true){
        cout << "Hello " << farmer.getFarmName() << "!" << endl;
        cout << "what action would you like to take?" << endl;
        cout << "" << endl;
        cout << "To view status, enter status" << endl;
        cout << "To visit the barn, enter barn" << endl;
        cout << "To visit the field, enter field" << endl;
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
        cout << "welcome to the barn! what action would you like to take?" << endl;
        cout << "" << endl;
        cout << "To buy an animal, enter buy" << endl;
        cout << "to purchase an upgrade, enter upgrade" << endl;
        cout << "To sell an animal, enter sell" << endl;
        cout << "to leave the barn, enter leave" << endl;
        cin >> optionChoice;
        if (optionChoice == "buy") {
            farmer.buyAnimal();
        } else if (optionChoice == "sell") {
            farmer.sellAnimal();
        } else if (optionChoice == "upgrade") {
            cout << "which upgrade would you like to buy?" << endl;
            cout << "" << endl;
            cout << "To upgrade speedGrowth, enter speed" << endl;
            cout << "To upgrade highYield, enter yield" << endl;
            cin >> optionChoice;
            if (optionChoice == "speed") {
                farmer.getCowArray()[0]->applySpeedGrowth(farmer);
            } else if (optionChoice == "yield") {
                farmer.getCowArray()[0]->applyHighYield(farmer);
            }
        }

    }

    while (fieldScreen == true) {

    }

        return 0;
    }

