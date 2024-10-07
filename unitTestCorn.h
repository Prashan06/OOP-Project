#ifndef UNITTESTCORN_H
#define UNITTESTCORN_H

#include "Corn.h"
#include "Farmer.h"
#include "Events.h"
 
using namespace std;

class unitTestCorn{

    protected:

    void testCorn(){

        Farmer testFarmer;
        Wheat testCorn;

        testCorn.Event(testFarmer);
    
        int modifiedSellPrice = testCorn.getSellPrice()*1.1;
        testCorn.applyHighYield(testFarmer);
        if (testCorn.getSellPrice() != modifiedSellPrice){
            cout << "Test failed" << endl;
        }

    }

    public:

        void runTests(){
            testCorn();
        }

};

#endif