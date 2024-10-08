#ifndef UNITTESTFIELD_H
#define UNITTESTFIELD_H

#include "Field.h"
#include "Farmer.h"
 
using namespace std;

class unitTestField{

    protected:

    void testField(){

        Field testField;
        Farmer testFarmer;

        testField.setHighYieldFactor(1.2);
        if (testField.getHighYieldFactor() != 1.2){
            cout << "Test failed" << endl;
        }

        testField.setPesticidePrice(2);
        if (testField.getPesticidePrice() != 2){
            cout << "Test failed" << endl;
        }

       testField.setHighYieldPrice(2);
       if (testField.getHighYieldPrice() != 2){
            cout << "Test failed" << endl;
       }

       bool pesticideApplied = true;
       testField.setPesticideApplied(pesticideApplied);
       if (testField.getPesticideApplied() != true){
            cout << "Test failed" << endl;
       }
       bool pesticideApplied = false;
       testField.setPesticideApplied(pesticideApplied);
       if (testField.getPesticideApplied() != false){
            cout << "Test failed" << endl;
       }
      
        testField.setSpeedGrowPrice(2);
        if (testField.getSpeedGrowPrice() != 2){
            cout << "Test failed" << endl;
        }

        testField.setSpeedGrowLevel(10);
        if (testField.getSpeedGrowLevel() != 10){
            cout << "Test failed" << endl;
        }

        testField.applySpeedGrowth(testFarmer.getMoneyCount()); //clarification of what apply speed growth actually does is needed
        if (testField.getSpeedGrowthApplied() != true){
            cout << "Test failed" << endl;
        }

        testField.applyPesticide();

    }

    public:

        void runTests(){
            testField();
        }

};

#endif


       
  