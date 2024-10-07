#include <iostream>
#include <string>
#include <random>

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

    Farmer ourfarmer;
    bool mainScreen = true;
    bool barnScreen, fieldScreen = false;
    string optionChoice;

    ourfarmer.setFarmName();

    while (mainScreen = true){

        cout << "Hello " << ourfarmer.getFarmName() << "!" << endl;
        cout << "What action would you like to take?" << endl;
        cout << "" << endl;
        cout << "To view status, enter status" << endl;
        cout << "To visit the Barn, enter barn" << endl;
        cout << "To visit the Field, enter field" << endl;
        cin >> optionChoice;
        if (optionChoice == "status") {
            ourfarmer.getStatus();
        } else if (optionChoice == "barn") {
            barnScreen = true;
            mainScreen = false;
        } else if (optionChoice == "field"){
            fieldScreen = true;
            mainScreen = false;
        }
        
    }

    while (barnScreen == true) {

        cout << "Welcome to the Barn! what action would you like to take?" << endl;
        cout << "" << endl;
        cout << "To buy an animal, enter buy" << endl;
        cout << "to purchase an upgrade, enter upgrade" << endl;
        cout << "To sell an animal, enter sell" << endl;
        cout << "To leave the Barn, enter leave" << endl;
        cin >> optionChoice;
        if (optionChoice == "buy") {
<<<<<<< HEAD
            farmer.buyAnimal();
            if (farmer.getCowCount() % 10 == 0) {
                random_device rd; // obtain a random number from hardware
                mt19937 gen(rd()); // seed the generator, initialise generator
                uniform_int_distribution<> distr(1, 10); // define the range
                int randomNumber = distr(gen);
                if (randomNumber == 1) {
                    farmer.getCowArray()[0]->Event(farmer);
                }
            } else if (farmer.getPigCount() % 10 == 0) {
                random_device rd; // obtain a random number from hardware
                mt19937 gen(rd()); // seed the generator, initialise generator
                uniform_int_distribution<> distr(1, 10); // define the range
                int randomNumber = distr(gen);
                if (randomNumber == 1) {
                    farmer.getPigArray()[0]->Event(farmer);
                }
            }
=======
            ourfarmer.buyAnimal();
>>>>>>> 3bb39ae0c6870ce2a537ed09a366157c398b250e
        } else if (optionChoice == "sell") {
            ourfarmer.sellAnimal();
        } else if (optionChoice == "upgrade") {
            cout << "which upgrade would you like to buy?" << endl;
            cout << "" << endl;
            cout << "To upgrade speedGrowth, enter speed" << endl;
            cout << "To upgrade highYield, enter yield" << endl;
            cin >> optionChoice;
            if (optionChoice == "speed") {
                ourfarmer.getCowArray()[0]->applySpeedGrowth(ourfarmer);
            } else if (optionChoice == "yield") {
                cout << "which animal would you like to apply highYield to, enter cow or pig" << endl;
                cin >> optionChoice;
                if (optionChoice == "cow"){
                    ourfarmer.getCowArray()[0]->applyHighYield(ourfarmer);
                } else if (optionChoice == "pig") {
                    ourfarmer.getPigArray()[0]->applyHighYield(ourfarmer);
                }
            }
        } else if (optionChoice == "leave") {
            mainScreen = true;
            barnScreen = false;
        }
    }

    while (fieldScreen == true) {
        cout << "welcome to the Field! what action would you like to take?" << endl;
        cout << "" << endl;
        cout << "To buy a crop, enter buy" << endl;
        cout << "to purchase an upgrade, enter upgrade" << endl;
        cout << "To sell a crop, enter sell" << endl;
        cout << "to leave the Field, enter leave" << endl;
        cin >> optionChoice;
        if (optionChoice == "buy") {
<<<<<<< HEAD
            farmer.buyCrop();
            if (farmer.getWheatCount() % 10 == 0) {
                random_device rd; // obtain a random number from hardware
                mt19937 gen(rd()); // seed the generator, initialise generator
                uniform_int_distribution<> distr(1, 10); // define the range
                int randomNumber = distr(gen);
                if (randomNumber == 1) {
                    farmer.getWheatArray()[0]->Event(farmer);
                }
            } else if (farmer.getCornCount() % 10 == 0) {
                random_device rd; // obtain a random number from hardware
                mt19937 gen(rd()); // seed the generator, initialise generator
                uniform_int_distribution<> distr(1, 10); // define the range
                int randomNumber = distr(gen);
                if (randomNumber == 1) {
                    farmer.getCornArray()[0]->Event(farmer);
                }
            }
=======
            ourfarmer.buyCrop();
>>>>>>> 3bb39ae0c6870ce2a537ed09a366157c398b250e
        } else if (optionChoice == "sell") {
            ourfarmer.sellCrop();
        } else if (optionChoice == "upgrade") {
            cout << "which upgrade would you like to buy?" << endl;
            cout << "" << endl;
            cout << "To upgrade speedGrowth, enter speed" << endl;
            cout << "To upgrade highYield, enter yield" << endl;
            cin >> optionChoice;
            if (optionChoice == "speed") {
                ourfarmer.getCornArray()[0]->applySpeedGrowth(ourfarmer);
            } else if (optionChoice == "yield") {
                cout << "which crop would you like to apply highYield to, enter corn or wheat" << endl;
                cin >> optionChoice;
                if (optionChoice == "corn"){
                    ourfarmer.getCornArray()[0]->applyHighYield(ourfarmer);
                } else if (optionChoice == "wheat") {
                    ourfarmer.getWheatArray()[0]->applyHighYield(ourfarmer);
                }
            }
        } else if (optionChoice == "leave") {
            mainScreen = true;
            fieldScreen = false;
        }
    }
        return 0;
    }

