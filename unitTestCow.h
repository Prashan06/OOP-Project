#ifndef UNITTESTCOW_H
#define UNITTESTCOW_H

#include "Cow.h"
#include "Farmer.h"
#include "Events.h"
 
using namespace std;

class unitTestCOw{

    protected:

    void testCow(){

        Farmer testFarmer;
        Cow testCow;

        testCow.Event(testFarmer);
    
        int modifiedSellPrice = testCow.getSellPrice()*1.1;
        testCow.applyHighYield(testFarmer);
        if (testCow.getSellPrice() != modifiedSellPrice){
            cout << "Test failed" << endl;
        }

    }

    public:

        void runTests(){
            testCow();
        }

};

#endif