#ifndef UNITTESTFARMER_H
#define UNITTESTFARMER_H

#include "Farmer.h"
using namespace std;

class unitTestFarmer {
    protected:
    void testFarmer(){
        Farmer f;
        // Enter a extremely long word to test input validation. Then enter name less than 20 characters
        f.setFarmName();
        // If number does not match the entered one, test has failed.
        f.getFarmName();
        f.setMoneyCount(100);
        if (f.getMoneyCount() != 100){
            cout << "Money count test failed" << endl;
        }
        f.setCornCount(10);
        if (f.getCornCount() != 10){
            cout << "Corn count test failed" << endl;
        }
        f.setCowCount(5);
        if (f.getCowCount() != 5){
            cout << "Cow count test failed" << endl;
        }      
        f.setPigCount(2);
        if (f.getPigCount() != 2){
            cout << "Pig count test failed" << endl;
        }       
        f.setWheatCount(4);
        if (f.getWheatCount() != 4){
            cout << "Wheat count test failed" << endl;
        }
        // Observe if details are same as outputted above.
        f.getStatus();
        // Buy 5 cows.
        f.buyItem();
        if (f.getMoneyCount() != 25){
            cout << "Buy Item - Money test failed" << endl;
        }
        if (f.getCowCount() != 10){
            cout << "Buy Item - cowCount test failed" << endl;
        }
        
        // enter a large amount of objects you want to buy. Should be more than you can afford.
        // Once error message appears buy 1 cow.
        f.buyItem();

        int blocker = 0;
        cout << "Wait 1 min and then enter a number " << endl;
        cin >> blocker;

        // Sell the 6 cows you bought
        f. sellItem();
        if (f.getMoneyCount() != 75 ){
            cout << "sellItem - Money test failed" << endl;
        }

        if (f.getCowCount() != 0){
            cout << "sellItem - cowCount test failed" << endl;
        }

        for (int i = 0; i < f.getCowCount(); i++){
            
        }

    }
    public:
    void runTests () {
        testFarmer();
    }

};


#endif