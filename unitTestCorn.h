#ifndef UNITTESTPIG_H
#define UNITTESTPIG_H

#include "Pig.h"
#include "Farmer.h"
#include "Events.h"
 
using namespace std;

class unitTestPig{

    protected:

    void testCorn(){

        Farmer testFarmer;
        Corn testCorn;

        testFarmer.setMoneyCount(50);
        testCorn.applyHighYield(testFarmer.getMoneyCount());

        if (testCorn.getCornHighYieldApplied() != true){
            cout << "applyHighYield test failed. " << endl;
        }

        if (*testFarmer.getMoneyCount() != 40 ) {
            cout << "Money - applyHighField failed. " << endl;
        }

        testFarmer.setCornCount(10);
        testCorn.Event(testFarmer.getCornCount());
        if (testCorn.getCornEvent() != true){
            cout << "Corn Event - Event failed. " << endl;
        } 
    }

    public:

        void runTests(){
            testCorn();
        }

};

#endif