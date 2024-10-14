/*#include <iostream>
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

    Farmer farmer;
    bool mainScreen = true;
    bool barnScreen, fieldScreen = false;
    string optionChoice;

    farmer.setFarmName(); 

    while (*farmer.getMoneyCount() > 0){
        cout << "Would you like to read in a savefile? enter Y or N" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if(optionChoice == "Y") {
            farmer.fileReader("savefile");
            cout << "starting bank balance is now" << *farmer.getMoneyCount() << endl;
        }

        while (mainScreen == true){

            cout << "Hello " << farmer.getFarmName() << "!" << endl;
            cout << "What action would you like to take?" << endl;
            cout << "" << endl;
            cout << "To view status, enter status" << endl;
            cout << "To visit the Barn, enter barn" << endl;
            cout << "To visit the Field, enter field" << endl;
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

            cout << "Welcome to the Barn! what action would you like to take?" << endl;
            cout << "" << endl;
            cout << "To buy an animal, enter buy" << endl;
            cout << "to purchase an upgrade, enter upgrade" << endl;
            cout << "To sell an animal, enter sell" << endl;
            cout << "To leave the Barn, enter leave" << endl;
            cin >> optionChoice;
            if (optionChoice == "buy") {
                farmer.buyAnimal();
                if (farmer.getProduct() == "cow"){
                  farmer.getCowArray()[0]->Event(farmer.getCowCount());
                } else if (farmer.getProduct() == "corn"){
                   farmer.getPigArray()[0]->Event(farmer.getPigCount());
                }
                farmer.executeEvent();
            } else if (optionChoice == "sell") {
                farmer.sellAnimal();
            } else if (optionChoice == "upgrade") {
                cout << "which upgrade would you like to buy?" << endl;
                cout << "" << endl;
                cout << "To use the speedGrowth update, enter speed" << endl;
                cout << "To use the highYield upgrade, enter yield" << endl;
                cin >> optionChoice;
                if (optionChoice == "speed") {
                    if (*farmer.getCowCount() > 0 || *farmer.getPigCount() > 0){
                        cout << "both animals must be purchased before upgrades can be applied" << endl;
                    }
                    farmer.getCowArray()[0]->applySpeedGrowth(farmer.getMoneyCount());
                    farmer.barnSpeedGrowthBought();
                } else if (optionChoice == "yield") {
                    if (*farmer.getCornCount() > 0 || *farmer.getWheatCount() > 0){
                        cout << "both animals must be purchased before upgrades can be applied" << endl;
                    }
                    cout << "which animal would you like to apply highYield to, enter cow or pig" << endl;
                    cin >> optionChoice;
                    if (optionChoice == "cow"){
                        farmer.getCowArray()[0]->applyHighYield(farmer.getMoneyCount());
                        farmer.highYieldBought();
                    } else if (optionChoice == "pig") {
                        farmer.getPigArray()[0]->applyHighYield(farmer.getMoneyCount());
                        farmer.highYieldBought();
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
                farmer.buyCrop();
                if (farmer.getProduct() == "corn"){
                    farmer.getCornArray()[0]->Event(farmer.getCornCount());
                }
                if (farmer.getProduct() == "Wheat") {
                    farmer.getWheatArray()[0]->Event(farmer.getWheatCount());
                }
                
                
                //farmer.executeEvent();
            } else if (optionChoice == "sell") {
                farmer.sellCrop();
            } else if (optionChoice == "upgrade") {
                cout << "which upgrade would you like to buy?" << endl;
                cout << "" << endl;
                cout << "To use the speedGrowth upgrade, enter speed" << endl;
                cout << "To use the highYield upgrade, enter yield" << endl;
                cin >> optionChoice;
                if (optionChoice == "speed") {
                    farmer.getCornArray()[0]->applySpeedGrowth(farmer.getMoneyCount());
                    farmer.fieldSpeedGrowthBought();
                } else if (optionChoice == "yield") {
                    cout << "which crop would you like to apply highYield to, enter corn or wheat" << endl;
                    cin >> optionChoice;
                    if (optionChoice == "corn"){
                        farmer.getCornArray()[0]->applyHighYield(farmer.getMoneyCount());
                        farmer.highYieldBought();
                    } else if (optionChoice == "wheat") {
                        farmer.getWheatArray()[0]->applyHighYield(farmer.getMoneyCount());
                        farmer.highYieldBought();
                    }
                }
            } else if (optionChoice == "leave") {
                mainScreen = true;
                fieldScreen = false;
            }
        }
    }
    farmer.fileWriter("savefile", farmer.getMoneyCount());
    farmer.~Farmer();
    return 0;
}
*/

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

    Farmer farmer;
    bool mainScreen = true;
    bool barnScreen, fieldScreen = false;
    string optionChoice;

    farmer.setFarmName();
    cout << "Would you like to read in a savefile? enter Y or N" << endl;
    cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if(optionChoice == "Y") {
            farmer.fileReader("savefile");
            cout << "starting bank balance is now " << *farmer.getMoneyCount() << endl;
        }

        if (optionChoice == "N"){
            cout << "Bank Balance is: " << *farmer.getMoneyCount() << endl;
        }
    while (*farmer.getMoneyCount() > 0){
        
        while (mainScreen == true){
            optionChoice = "";
            cout << "Hello " << farmer.getFarmName() << "!" << endl;
            cout << "What action would you like to take?" << endl;
            cout << "" << endl;
            cout << "To view status, enter status" << endl;
            cout << "To visit the Barn, enter barn" << endl;
            cout << "To visit the Field, enter field" << endl;
            cin >> optionChoice;

            while (optionChoice != "barn" && optionChoice != "field" && optionChoice != "status"){
                cout << "Invalid input, reenter your choice of action. Choose, barn, field, or status." << endl;
                cin >> optionChoice;
            }
            if (optionChoice == "status") {
                farmer.getStatus(); //displaying how many cows, pigs, wheat & corn the player has
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
            while (optionChoice != "buy" && optionChoice != "upgrade" && optionChoice != "sell" && optionChoice != "leave"){
                cout << "Invalid input, reenter your choice of action. Choose, buy, upgrade, sell, or leave ." << endl;
                cin >> optionChoice;
            }
            if (optionChoice == "buy") {
                farmer.buyAnimal();
                if (farmer.getProduct() == "cow" && *farmer.getCowCount() > 9){
                    for (int i = 0; i < *farmer.getCowCount(); i++){
                        farmer.getCowArray()[i]->Event(farmer.getCowCount());
                    }
                    farmer.executeEvent();
                } else if (farmer.getProduct() == "pig" && *farmer.getPigCount() > 9){
                    for (int i = 0; i < *farmer.getPigCount(); i++){
                        farmer.getPigArray()[i]-> Event(farmer.getPigCount());
                    }
                    farmer.executeEvent();
                }
            } else if (optionChoice == "sell") {
                farmer.sellAnimal();
            } else if (optionChoice == "upgrade") {
                cout << "which upgrade would you like to buy?" << endl;
                cout << "" << endl;
                cout << "To upgrade speedGrowth, enter speed" << endl;
                cout << "To upgrade highYield, enter yield" << endl;
                cin >> optionChoice;
                if (optionChoice == "speed") {
                    //if (*farmer.getCowCount() > 0 || *farmer.getPigCount() > 0){
                        //cout << "both animals must be purchased before upgrades can be applied" << endl;
                    //}
                    //farmer.getCowArray()[0]->applySpeedGrowth(farmer.getMoneyCount());
                    //farmer.barnSpeedGrowthBought();
                    farmer.applySpeedGrowAnimals();
                } else if (optionChoice == "yield") {
                    /*if (*farmer.getCornCount() > 0 || *farmer.getWheatCount() > 0){
                        cout << "both animals must be purchased before upgrades can be applied" << endl;
                    }
                    cout << "which animal would you like to apply highYield to, enter cow or pig" << endl;
                    cin >> optionChoice;
                    if (optionChoice == "cow"){
                        farmer.getCowArray()[0]->applyHighYield(farmer.getMoneyCount());
                        farmer.highYieldBought();
                    } else if (optionChoice == "pig") {
                        farmer.getPigArray()[0]->applyHighYield(farmer.getMoneyCount());
                        farmer.highYieldBought();
                    }*/
                   farmer.applyHighYieldAnimals();
                }
            } else if (optionChoice == "leave") {
                cout << "Leaving the Barn..." << endl;  // Debug statement
                barnScreen = false;
                mainScreen = true;
                cout << "mainScreen: " << mainScreen << ", barnScreen: " << barnScreen << endl; // Debug statement
            }
        }

        while (fieldScreen == true) {
            cout << "welcome to the Field! what action would you like to take?" << endl;
            cout << "" << endl;
            cout << "To buy a crop, enter buy" << endl;
            cout << "to purchase an upgrade, enter upgrade" << endl;
            cout << "To purchase pesticide, enter pesticide" << endl;
            cout << "To sell a crop, enter sell" << endl;
            cout << "to leave the Field, enter leave" << endl;
            cin >> optionChoice;
            while (optionChoice != "buy" && optionChoice != "upgrade" && optionChoice != "sell" && optionChoice != "pesticide" && optionChoice != "leave"){
                cout << "Invalid input, reenter your choice of action. Choose, buy, upgrade, sell, pesticide, or leave ." << endl;
                cin >> optionChoice;
            }
            if (optionChoice == "buy") {
                farmer.buyCrop();
                if (farmer.getProduct() == "corn" && *farmer.getCornCount() > 9){
                    for (int i = 0; i < *farmer.getCornCount(); i++){
                        farmer.getCornArray()[i]->Event(farmer.getCornCount());
                        //line below is for debugging, needs to be taken out.
                        cout << "" << i << " " << farmer.getCornArray()[i]->getCornEvent() << endl;
                    }
                    farmer.executeEvent();
                }
                if (farmer.getProduct() == "Wheat" && *farmer.getWheatCount() > 9) {
                    for (int i = 0; i < *farmer.getWheatCount(); i++){
                        farmer.getWheatArray()[i]->Event(farmer.getWheatCount());
                        //line below is for debugging, needs to be taken out.
                        cout << "" << i << " " << farmer.getWheatArray()[i]->getWheatEvent() << endl;
                    }
                    farmer.executeEvent();
                }
            } else if (optionChoice == "sell") {
                farmer.sellCrop();
            } else if (optionChoice == "upgrade") {
                cout << "which upgrade would you like to buy?" << endl;
                cout << "" << endl;
                cout << "To upgrade speedGrowth, enter speed" << endl;
                cout << "To upgrade highYield, enter yield" << endl;
                cin >> optionChoice;
                while (optionChoice != "speed" && optionChoice != "yield" ){
                    cout << "Invalid input, reenter your choice of action,  choose speed or yield." << endl;
                    cin >> optionChoice;
                }
                if (optionChoice == "speed") {
                    //farmer.getCornArray()[0]->applySpeedGrowth(farmer.getMoneyCount());
                    //farmer.fieldSpeedGrowthBought();
                    farmer.applySpeedGrowCrops();
                } else if (optionChoice == "yield") {
                    /*cout << "which crop would you like to apply highYield to, enter corn or wheat" << endl;
                    cin >> optionChoice;
                    if (optionChoice == "corn"){
                        farmer.getCornArray()[0]->applyHighYield(farmer.getMoneyCount());
                        farmer.highYieldBought();
                    } else if (optionChoice == "wheat") {
                        farmer.getWheatArray()[0]->applyHighYield(farmer.getMoneyCount());
                        farmer.highYieldBought();
                    }*/
                   farmer.applyHighYieldCrops();
                } else if (optionChoice == "pesticide"){
                    
                }
            } else if (optionChoice == "leave") {
                mainScreen = true;
                fieldScreen = false;
            }
        }
    }
    farmer.fileWriter("savefile", farmer.getMoneyCount()); //saving progress/money, writing onto file
    farmer.~Farmer(); //calling destructor for farmer
    return 0;
}