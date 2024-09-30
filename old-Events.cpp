#include <iostream>
#include <random>
#include "Events.h"
#include "Farmer.h"
#include "Pigs.h"
#include "Cows.h"
#include "Corn.h"
#include "Wheat.h"
#include "Barn.h"
//#include "SprayingMachine.h"
//#include "FertilizingMachine.h"
//#include "Tools.h"

using namespace std;

void Events::executeEvent(Farmer farmer, Cows cow, Pigs pig, Barn barn, SprayingMachine sMachine, FertilizingMachine fMachine) {
    if (farmer.nextDay() % farmer.getDayLength() == 0) {
        // method to give random chance of event occuring every new day
        random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator, initialise generator
        uniform_int_distribution<> distr(1, 3); // define the range

        int randomNumber = distr(gen); // generate random integer number

        // defining and implementing the events 

        switch (randomNumber) {

            case 1:
                cout << "A pest infestation has taken over your farm!" << endl;
                // cout << "Would you like to buy pesticide for " << pesticide price << "dollars?" << endl;
                // cin >> optionChoice
                //while (optionChoice != "Y" && optionChoice != "N") {
                //cout << "invalid input! please enter Y or N" << endl;
                //cin >> optionChoice;
                //}

                //if (optionChoice == "Y") {
                    // implement pesticide function from tools;
                //} else {
                    //method to halve crops;
                //}
                

            case 2:
                // prompt user about event

                cout << "A disease has spread throughout your barn!" << endl;
                cout << "half of your animals have died" << endl;

                // half the amount of cows in the barn

                int cowCounter = 0;
                int i = 0;
                while (cowCounter < (cow.getCowCount())/2) {
                    cowCounter = cowCounter + cow.getCowArray()[i];
                    i++;
                }
                i--; // as index of array starts at 0;
                cow.getCowArray()[i] = cow.getCowArray()[i] - (cowCounter - ((cow.getCowCount())/2));
                for (int j = i; j < cow.getNumberOfTimesCowsAreBought(); j++) {
                    cow.getCowArray()[j] = cow.getCowArray()[j - i];
                    cow.getTimeArray()[j] = cow.getTimeArray()[j - i];
                }
                cow.setCowCount((cow.getCowCount()/2));
                cow.setNumberOfTimesCowsAreBought((cow.getNumberOfTimesCowsAreBought() - i));

                // half the amount of pigs in the barn

                int pigCounter = 0;
                int k = 0;
                while (pigCounter < (pig.getPigCount())/2) {
                    pigCounter = pigCounter + pig.getPigArray()[k];
                    k++;
                }
                k--; // as index of array starts at 0
                pig.getPigArray()[k] = pig.getPigArray()[k] - (pigCounter - ((pig.getPigCount())/2));
                for (int l = k; l < pig.getNumberOfTimesPigsAreBought(); l++) {
                    pig.getPigArray()[l] = pig.getPigArray()[l - k];
                    pig.getTimeArray()[l] = pig.getTimeArray()[l - k];
                }
                
                pig.setPigCount((pig.getPigCount()/2));
                pig.setNumberOfTimesPigsAreBought((pig.getNumberOfTimesPigsAreBought() - k));
                barn.setAnimalCount(pig.getPigCount(), cow.getCowCount());
                break;

            case 3:
                // prompt user about event
                cout << "Its tax day! you must pay your taxes." << endl;
                cout << "100 dollars has been payed to the tax office" << endl;

                farmer.setMoneyCount((farmer.getMoneyCount() - 100));
                break;

            case 4:

                cout << "Your spraying machine has broken" << endl;
                cout << "100 dollers must be paid to repair it" << endl;

                repairedtoFalse(sMachine);

                break;

            case 5: 

                cout << "Your FertilingMachine has broken" << endl;
                cout << "100 dollers must be paid to repair it" << endl;

                repairedtoFalse(fMachine);  
            
            default: 
                break;
        }
    }
}
