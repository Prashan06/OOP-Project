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

        testPig.Event(testFarmer);
    
        int modifiedSellPrice = testPig.getSellPrice()*1.1;
        testPig.applyHighYield(testFarmer);
        if (testPig.getSellPrice() != modifiedSellPrice){
            cout << "Test failed" << endl;
        }

    }

    public:

        void runTests(){
            testWheat();
        }

};

#endif