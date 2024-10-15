#include <iostream>
#include <random>
#include <string>

#include "Barn.h"
#include "Corn.h"
#include "Cow.h"
#include "Events.h"
#include "Farm.h"
#include "Farmer.h"
#include "Field.h"
#include "Pig.h"
#include "Wheat.h"

using namespace std;

// main file that will define the method for the player to play the game

int main() {
  // initialising global variables to be used throughout the course of the game

  Farmer farmer;
  bool mainScreen = true;
  bool barnScreen, fieldScreen = false;
  string optionChoice;

  farmer.setFarmName();  // requesting and storing farm name
  cout << "Would you like to read in a savefile? enter Y or N" << endl;
  cin >> optionChoice;  // reading user input
  while (optionChoice != "Y" &&
         optionChoice != "N") {  // validating input and rerequesting if invalid
    cout << "invalid input! please enter Y or N" << endl;
    cin >> optionChoice;  // reading user input
  }
  if (optionChoice == "Y") {  // updating money variable in farmer to match
                              // saved value and displayng it
    farmer.fileReader("savefile");
    cout << "starting bank balance is now " << *farmer.getMoneyCount() << endl;
  }

  if (optionChoice == "N") {  // displaying default bank balance
    cout << "Bank Balance is: " << *farmer.getMoneyCount() << endl;
  }
  while (*farmer.getMoneyCount() > 0) {
    while (mainScreen == true) {
      optionChoice = "";  // displaying options available to the player
      cout << "Hello " << farmer.getFarmName() << "!"
           << endl;  // welcoming player with inputed name
      cout << "What action would you like to take?" << endl;
      cout << "" << endl;
      cout << "To view status, enter status" << endl;
      cout << "To visit the Barn, enter barn" << endl;
      cout << "To visit the Field, enter field" << endl;
      cout << "To quit the game, enter quit" << endl;
      cin >> optionChoice;  // reading user input

      while (
          optionChoice != "barn" && optionChoice != "field" &&
          optionChoice != "status" &&
          optionChoice !=
              "quit") {  // validating input and rerequesting input if invalid
        cout << "Invalid input, re-enter your choice of action. Choose, barn, "
                "field, or status."
             << endl;
        cin >> optionChoice;  // reading user input
      }
      if (optionChoice == "status") {
        farmer.getStatus();  // displaying how many cows, pigs, wheat & corn the
                             // player has
      } else if (optionChoice == "barn") {  // exiting mainScreen loop and
                                            // entering barnScreen loop
        barnScreen = true;
        mainScreen = false;
      } else if (optionChoice == "field") {  // exiting mainScreen loop and
                                             // entering fieldScreen loop
        fieldScreen = true;
        mainScreen = false;
      } else if (optionChoice == "quit") {
        farmer.fileWriter(
            "savefile",
            farmer
                .getMoneyCount());  // saving progress/money, writing onto file
        *farmer.getMoneyCount() = 0;  // intializing farmer money count such
                                      // that the game loop can be exited
        cout << "Game has ended" << endl;
        mainScreen = false;  // exiting mainScreen loop
      }
    }

    while (barnScreen == true) {
      cout << "Welcome to the Barn! what action would you like to take?"
           << endl;  // displaying options available to the player
      cout << "" << endl;
      cout << "To buy an animal, enter buy" << endl;
      cout << "to purchase an upgrade, enter upgrade" << endl;
      cout << "To sell an animal, enter sell" << endl;
      cout << "To leave the Barn, enter leave" << endl;
      cin >> optionChoice;  // reading user input
      while (optionChoice != "buy" && optionChoice != "upgrade" &&
             optionChoice != "sell" &&
             optionChoice !=
                 "leave") {  // validating input & rerequesting if invalid
        cout << "Invalid input, re-enter your choice of action. Choose, buy, "
                "upgrade, sell, or leave ."
             << endl;
        cin >> optionChoice;  // reading user input
      }
      if (optionChoice == "buy") {
        farmer.buyAnimal();  // calling buyAnimal function (requests user input)
        if (farmer.getProduct() == "cow" && *farmer.getCowCount() > 9) {
          for (int i = 0; i < *farmer.getCowCount();
               i++) {  // iterating through cow array
            farmer.getCowArray()[i]->Event(farmer.getCowCount());
          }
          farmer.executeEvent();  // calling executeEvent function
        } else if (farmer.getProduct() == "pig" && *farmer.getPigCount() > 9) {
          for (int i = 0; i < *farmer.getPigCount();
               i++) {  // iterating through pig array
            farmer.getPigArray()[i]->Event(farmer.getPigCount());
          }
          farmer.executeEvent();  // calling executeEvent function
        }
      } else if (optionChoice == "sell") {
        farmer
            .sellAnimal();  // calling sellAnimal function (reuqests user input)
      } else if (optionChoice == "upgrade") {
        cout << "which upgrade would you like to buy?" << endl;
        cout << "" << endl;
        cout << "To upgrade speedGrowth, enter speed" << endl;
        cout << "To upgrade highYield, enter yield" << endl;
        cin >> optionChoice;  // reading user input
        while (
            optionChoice != "yield" &&
            optionChoice !=
                "speed") {  // validating user input & rerequesting if invalid
          cout << "Invalid input enter speed or yield" << endl;
          cin >> optionChoice;  // reading uesr input
        }
        if (optionChoice == "speed") {
          farmer.applySpeedGrowAnimals();  // calling applySpeedGrowAnimals
                                           // function (requests user input)
        } else if (optionChoice == "yield") {
          farmer.applyHighYieldAnimals();  // calling applyHighYieldAnimals
                                           // function (requests user input)
        }
      } else if (optionChoice == "leave") {  // exiting barnScreen loop
        barnScreen = false;
        mainScreen = true;
      }
    }

    while (fieldScreen == true) {
      cout << "welcome to the Field! what action would you like to take?"
           << endl;  // displays options available to player
      cout << "" << endl;
      cout << "To buy a crop, enter buy" << endl;
      cout << "to purchase an upgrade, enter upgrade" << endl;
      cout << "To purchase pesticide, enter pesticide" << endl;
      cout << "To sell a crop, enter sell" << endl;
      cout << "to leave the Field, enter leave" << endl;
      cin >> optionChoice;  // reading user input
      while (optionChoice != "buy" && optionChoice != "upgrade" &&
             optionChoice != "sell" && optionChoice != "pesticide" &&
             optionChoice !=
                 "leave") {  // validating user input & rerequesting if invalid
        cout << "Invalid input, re-enter your choice of action. Choose, buy, "
                "upgrade, sell, pesticide, or leave ."
             << endl;
        cin >> optionChoice;
      }
      if (optionChoice == "buy") {
        farmer.buyCrop();  // calling buyCrop function (requests user input)
        if (farmer.getProduct() == "corn" && *farmer.getCornCount() > 9) {
          for (int i = 0; i < *farmer.getCornCount();
               i++) {  // iterating through corn array
            farmer.getCornArray()[i]->Event(farmer.getCornCount());
          }
          farmer.executeEvent();  // calling executeEvent function
        }
        if (farmer.getProduct() == "Wheat" && *farmer.getWheatCount() > 9) {
          for (int i = 0; i < *farmer.getWheatCount();
               i++) {  // iterating through wheat array
            farmer.getWheatArray()[i]->Event(farmer.getWheatCount());
          }
          farmer.executeEvent();  // calling executeEvent function
        }
      } else if (optionChoice == "sell") {
        farmer.sellCrop();  // calling sellCrop function (requests user input)
      } else if (optionChoice == "upgrade") {
        cout << "which upgrade would you like to buy?" << endl;
        cout << "" << endl;
        cout << "To upgrade speedGrowth, enter speed" << endl;
        cout << "To upgrade highYield, enter yield" << endl;
        cin >> optionChoice;  // reading user input
        while (optionChoice != "speed" &&
               optionChoice !=
                   "yield") {  // validating input & rerequesting if invalid
          cout << "Invalid input, re-enter your choice of action,  choose "
                  "speed or yield."
               << endl;
          cin >> optionChoice;
        }
        if (optionChoice == "speed") {
          farmer.applySpeedGrowCrops();  // calling applySpeedGrowCrops function
                                         // (requests user input)
        } else if (optionChoice == "yield") {
          farmer.applyHighYieldCrops();  // calling applyHighYieldCrops function
                                         // (requests user input)
        }
      } else if (optionChoice == "pesticide") {
        farmer.appliedPesticide();  // calling appliedPesticide function
                                    // (requests user input)
      } else if (optionChoice == "leave") {  // exiting fieldScreen loop
        mainScreen = true;
        fieldScreen = false;
      }
    }
  }
  farmer.~Farmer();  // calling destructor for farmer
  return 0;
}