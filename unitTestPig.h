#ifndef UNITTESTPIG_H
#define UNITTESTPIG_H

#include "Pig.h"
#include "Farmer.h"
#include "Events.h"
 
using namespace std;

class unitTestPig{

    protected:

    void testPig(){

        Farmer testFarmer;
        Pig testPig;

        testFarmer.setMoneyCount(50);
        testPig.applyHighYield(testFarmer.getMoneyCount());

        if (testPig.getPigHighYieldApplied() != true){
            cout << "applyHighYield test failed. " << endl;
        }

        if (*testFarmer.getMoneyCount() != 35 ) {
            cout << "Money - applyHighField failed. " << endl;
        }

        testFarmer.setPigCount(10);
        testPig.Event(testFarmer.getPigCount());
        if (testPig.getPigEvent() != true){
            cout << "Pig Event - Event failed. " << endl;
        } 
    }

    public:

        void runTests(){
            testPig();
        }

};

#endif