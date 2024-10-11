#ifndef UNITTESTFARMER_H
#define UNITTESTFARMER_H

#include "Farmer.h"
using namespace std;

class unitTestFarmer {
    protected:
    void testFarmer(){
    }
    public:
        void SetGetCountStatus(){
                    // Enter a extremely long word to test input validation. Then enter name less than 20 characters
        f.setFarmName();
        // If number does not match the entered one, test has failed.
        f.getFarmName();
        f.setMoneyCount(100);
        if (*f.getMoneyCount() != 100){
            cout << "Money count test failed" << endl;
        }
        f.setCornCount(10);
        if (*f.getCornCount() != 10){
            cout << "Corn count test failed" << endl;
        }
        f.setCowCount(5);
        if (*f.getCowCount() != 5){
            cout << "Cow count test failed" << endl;
        }      
        f.setPigCount(2);
        if (*f.getPigCount() != 2){
            cout << "Pig count test failed" << endl;
        }       
        f.setWheatCount(4);
        if (*f.getWheatCount() != 4){
            cout << "Wheat count test failed" << endl;
        }
        // Observe if details are same as outputted above.
        f.getStatus();
        }

        void buyAnimal(){
            Farmer f;
            f.setMoneyCount(100);
            // Buy 5 cows
            if (*f.getMoneyCount() != 25){
                cout << "Buy Item - Money test failed" << endl;
            }
            if (*f.getCowCount() != 5){
                cout << "Buy Item - cowCount test failed" << endl;
            }
        }

        void sellAnimal(){
            Farmer f;
            // Buy 5 cows.
            f.buyAnimal();
            // Wait 30 seconds and sell the cows.
            f.sellAnimal();
            if (f.getCowCount() != 0){
                cout << "Sell Animal failed" << endl;
            }
        }

        void buyCrop(){
            Farmer f;
            f.setMoneyCount(100);
            if (*f.getMoneyCount() != 25){
                cout << "Buy Item - Money test failed" << endl;
            }
            if (*f.getCornCount() != 5){
                cout << "Buy Item - cornCount test failed" << endl;
            }
        }

        void sellCrop(){
            Farmer f;
            // Buy 5 corn.
            f.buyCrop();
            // Wait 30 seconds and sell the corn.
            f.sellCrop();
            if (f.getCornCount() != 0){
                cout << "Sell Crop failed" << endl;
            }
        }

        void testFieldSpeedGrow(){
            Farmer f;
            f.setMoneyCount(100);
            f.buyCrop();
            f.fieldSpeedGrowthBought();
            for (int i = 0; i < *f.getCornCount(); i++){
                if ()
            }
        }
};


#endif