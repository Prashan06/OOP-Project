#include <iostream>
#include <string>
#include "Events.h"
#include "Tools.h"

using namespace std;

Tools::Tools() : cropEnhancer ("Crop Enhancer"), cropEnhancerLevel(0), animalFeed(0), animalFeedLevel(0), animalFeedPrice(30), cropEnhancerPrice(25), optionChoice("") {}

void Tools::upgradeCropEnhancer() {
    if (cropEnhancerLevel == 0) {
        cout << "Would you like to buy the " << cropEnhancer << " for " << cropEnhancerPrice << " dollars? Enter Y or N" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == "Y") {
            cropEnhancerLevel++;
        }
    } 
    if (cropEnhancerLevel >= 1) {
        cout << "Would you like to upgrade " << cropEnhancer << " for " << cropEnhancerPrice << " dollars? Enter Y or N" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == "Y") {
            cropEnhancerLevel++;
            sellReadyWheatPrice++;
            sellReadyCornPrice++;
            cout << "Wheat now sells for: " << sellReadyWheatPrice << endl;
            cout << "Corn now sells for: " << sellReadyCornPrice << endl;
        }
    }
}

void Tools::upgradeAnimalFeed() {
    if (animalFeedLevel == 0) {
        cout << "Would you like to buy " << animalFeed << " for " << animalFeedPrice << " dollars? Enter Y or N" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == "Y") {
            animalFeedLevel++;
        }
    } 
    if (animalFeedLevel >= 1) {
        cout << "Would you like to upgrade " << animalFeed << " for " << animalFeedPrice << " dollars? Enter Y or N" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == "Y") {
            animalFeedLevel++;
            pigGrowthRate--;
            cowGrowthRate--;
            cout << "Pig growth rate is now: " << pigGrowthRate << " seconds" << endl;
            cout << "Cow growth rate is now: " << cowGrowthRate << " seconds" << endl;
        }
    }
}

int Tools::getCropEnhancerLevel() {
    return cropEnhancerLevel;
}

int Tools::getAnimalFeedLevel() {
    return animalFeedLevel;
}


