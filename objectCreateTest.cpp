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

        int numberCanUpgrade = money/functionWheat->getHighYieldPrice;

        cout << "you have " << highYieldNotApplied << " wheat that are not upgraded " << endl;
        cout << "You can upgrade" << numberCanUpgrade << "of them, enter the number that you would like to upgrade or 0 to exit" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == "Y") {
            for (int i = 0; i < wheatCount; ++i) {
                if (j < optionChoice){}
                if ((currentTime - (wheat[i]->getTimer())) < wheat[i]->getSellTime()){
                    newWheatArray[j] = wheat[i];
                    j++;
                } else {
                    delete wheat[i];
                }
            }
            money = money + newMoney;
            wheat = newWheatArray;
            setWheatCount(wheatCount - readyToSellCount);

    }else if (product == "corn"){
    }//
} //
        

