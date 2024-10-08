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

        testBarn.applySpeedGrowth(testFarmer.getMoneyCount()); //clarification of what apply speed growth actually does is needed
        if (testBarn.getSpeedGrowthApplied() != true){
            cout << "Test failed" << endl;
        }

    }

    public:

        void runTests(){
            testBarn();
        }

};

#endif