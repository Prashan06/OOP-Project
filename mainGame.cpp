#include <iostream>
#include <string>
#include <fstream>
#include "progress.txt" // needs editing

#include "Farm.h"
#include "Farmer.h"
#include "Corn.h"
#include "Wheat.h"
#include "Pigs.h"
#include "Cows.h"

using namespace std;

int main(){

//Logic for mainGame

Farmer player;

ifstream inputFile("progress.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening the file!" << endl;
    }

    string stringMoney;

    while (getline(inputFile, stringMoney)) {
        cout << "Your have " << stringMoney << " in the bank" << endl;
        
        int newMoney = player.getMoneyCount() + stoi(stringMoney);
        player.setMoneyCount(newMoney);
    }

    inputFile.close(); 

};
