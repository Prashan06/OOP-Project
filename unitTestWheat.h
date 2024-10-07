#ifndef UNITTESTWHEAT_H
#define UNITTESTWHEAT_H

#include "Wheat.h"
#include "Farmer.h"
#include "Events.h"
 
using namespace std;

class unitTestWheat{

    protected:

    void testWheat(){

        Farmer testFarmer;
        Wheat testWheat;

        // follow instruction to buy 10 wheat

        testFarmer.buyCrop();

        int initialWheatCount = testFarmer.getWheatCount();

        testWheat.Event(testFarmer);

        int (initialWheatCount != (2*testFarmer.getWheatCount())){
            cout << "Test failed" << endl;
        }
    
        float modifiedSellPrice = testWheat.getSellPrice()*1.1;
        testWheat.applyHighYield(testFarmer);
        if (testWheat.getSellPrice() != modifiedSellPrice){
            cout << "Test failed" << endl;
        }

    }

    public:

        void runTests(){
            testWheat();
        }

};

#endif