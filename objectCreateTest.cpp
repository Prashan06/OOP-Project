#include <string>
#include <iostream>

using namespace std;

void Farmer::upgradeCrop(){

    string product;

    Wheat functionWheat;

    cout << "What crop would you like to upgrade? wheat or corn? (Enter response in lower case)" << endl;
    cin >> product;

    while (product != "wheat" && product != "corn"){
        cout << "invalid input! please enter wheat or corn" << endl;
        cin >> product;
    }

    if (product == "wheat"){ //

        int option;
        int newMoney = 0;
        int highYieldNotAppliedCount;

        for (int i = 0; i < wheatCount; ++i){
            if ((wheat[i]->getIsHighYieldApplied()) == false){
                newMoney = newMoney + wheat[i]->getHighYieldPrice();
                highYieldNotAppliedCount++;
            }
        }

        int numberCanUpgrade = *money/functionWheat->getHighYieldPrice;

        cout << "You have " << highYieldNotAppliedCunt << " wheat that are not upgraded " << endl;
        cout << "You can upgrade" << numberCanUpgrade << "of them, enter the number that you would like to upgrade or 0 to exit" << endl;
        cin >> optionChoice;
        while (optionChoice != 0 || optionChoice != 0:optionChoice) {
            cout << "invalid input! please enter a valid number" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == 1:optionChoice) {
            for (int i = 0; i < wheatCount; ++i) {
                if (j < optionChoice){
                    wheat[i].applyHighYield();
                    j++;
                    money = money - wheat[i]->getHighYieldPrice();
                } else {
                    break;
                }
            }

    }else if (product == "corn"){

        int option;
        int newMoney = 0;
        int highYieldNotAppliedCount;

        for (int i = 0; i < wheatCount; ++i){
            if ((wheat[i]->getIsHighYieldApplied()) == false){
                newMoney = newMoney + wheat[i]->getHighYieldPrice();
                highYieldNotAppliedCount++;
            }
        }

        int numberCanUpgrade = *money/functionWheat->getHighYieldPrice;

        cout << "You have " << highYieldNotAppliedCunt << " wheat that are not upgraded " << endl;
        cout << "You can upgrade" << numberCanUpgrade << "of them, enter the number that you would like to upgrade or 0 to exit" << endl;
        cin >> optionChoice;
        while (optionChoice != 0 || optionChoice != 0:optionChoice) {
            cout << "invalid input! please enter a valid number" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == 1:optionChoice) {
            for (int i = 0; i < wheatCount; ++i) {
                if (j < optionChoice){
                    wheat[i].applyHighYield();
                    j++;
                    money = money - wheat[i]->getHighYieldPrice();
                } else {
                    break;
                }
            }
    }//
} //
        

