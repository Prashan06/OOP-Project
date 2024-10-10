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
        testFarmer.setMoneyCount(50);
        testWheat.applyHighYield(testFarmer.getMoneyCount());

        if (testWheat.getWheatHighYieldApplied() != true){
            cout << "applyHighYield test failed. " << endl;
        }

        if (*testFarmer.getMoneyCount() != 25) {
            cout << "Money - applyHighField failed. " << endl;
        }

        testFarmer.setWheatCount(10);
        testWheat.Event(testFarmer.getWheatCount());
        if (testWheat.getWheatEvent() != true){
            cout << "Wheat Event - Event failed. " << endl;
        } 
    }

    public:

        void runTests(){
            testWheat();
        }

};

#endif