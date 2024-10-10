#ifndef UNITTESTCOW_H
#define UNITTESTCOW_H

#include "Cow.h"
#include "Farmer.h"
#include "Events.h"
 
using namespace std;

class unitTestCow{

    protected:

    void testCow(){

        Farmer testFarmer;
        Cow testCow;
        
        testFarmer.setMoneyCount(50);
        testCow.applyHighYield(testFarmer.getMoneyCount());


        if (testCow.getCowHighYieldApplied() != true){
            cout << "applyHighYield test failed. " << endl;
        }


        if (*testFarmer.getMoneyCount() != 40) {
            cout << "Money - applyHighField failed. " << endl;
        }

        testFarmer.setCowCount(10);
        testCow.Event(testFarmer.getCowCount());
        if (testCow.getCowEvent() != true){
            cout << "Cow Event - Event failed. " << endl;
        } 
    }

    public:

        void runTests(){
            testCow();
        }

};

#endif