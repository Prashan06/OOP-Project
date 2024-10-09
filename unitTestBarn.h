#ifndef UNITTESTBARN_H
#define UNITTESTBARN_H

#include "Barn.h"
#include "Farmer.h"
 
using namespace std;

class unitTestBarn{

    protected:

    void testBarn(){

        Barn testBarn;
        Farmer testFarmer;

        testBarn.setHighYieldFactor(1.2);
        if (testBarn.getHighYieldFactor() != 1.2){
            cout << "Test failed" << endl;
        }

       testBarn.setHighYieldPrice(2);
       if (testBarn.getHighYieldPrice() != 2){
            cout << "Test failed" << endl;
       }
      
        testBarn.setSpeedGrowPrice(2);
        if (testBarn.getSpeedGrowPrice() != 2){
            cout << "Test failed" << endl;
        }

        testBarn.setSpeedGrowLevel(10);
        if (testBarn.getSpeedGrowLevel() != 10){
            cout << "Test failed" << endl;
        }

       bool speedGrowApplied = true;
       testBarn.setspeedGrowApplied(speedGrowApplied);
       if (testBarn.getPesticideApplied() != true){
            cout << "Test failed" << endl;
       }

       bool speedGrowApplied = false;
       testBarn.setSpeedGrowApplied(speedGrowApplied);
       if (testBarn.getSpeedGrowApplied() != false){
            cout << "Test failed" << endl;
       }

        int initialMoney = *testFarmer.getMoneyCount();
        testBarn.applySpeedGrowth(testFarmer.getMoneyCount()); 
        if ((testBarn.getSpeedGrowApplied() != true) && (*testFarmer.getMoneyCount() != initialMoney - 2) && (testBarn.getSpeedGrowLevel() != 11)){
            cout << "Test failed" << endl;
        }
        
    }

    public:

        void runTests(){
            testBarn();
        }

};

#endif