#ifndef UNITTESTFIELD_H
#define UNITTESTFIELD_H

#include "Field.h"

using namespace std;

class unitTestField{

    public:

    void testField(){
        // Execute functions below.
        testHighYield();
        testSpeedGrowPrice();
        testSpeedGrowApplied();
    }

    protected:
        void testHighYield(){
            Field testField;
            // Set the highYieldFactor to 1.
            testField.setHighYieldFactor(1);
            // Check if getHighYieldFactor() works as expected.
            if (testField.getHighYieldFactor() != 1){
                // Error message.
                cout << "Test failed1" << endl;
            }

            // Set the highYieldFactor to 2.
            testField.setHighYieldPrice(2);
            // Check if getHighYieldFactor() works as expected.
            if (testField.getHighYieldPrice() != 2){
                // Error message. 
                    cout << "Test failed2" << endl;
            }
        }

        void testSpeedGrowPrice(){
            Field testField;
            // setSpeedGrowPrice to 2.
            testField.setSpeedGrowPrice(2);
            // Check if setSpeedGrowPrice sets the speedGrowPrice variable to 2.
            if (testField.getSpeedGrowPrice() != 2){
                // error message.
                cout << "Test failed3" << endl;
            }           
        }

        void testSpeedGrowLevel(){
            Field testField;
            //Set speedGrowLevel to 10; 
            testField.setSpeedGrowLevel(10);
            // Check if setSpeedGrowPrice sets the speedGrowPrice variable to 10.
            if (testField.getSpeedGrowLevel() != 10){
                // Error message.
                cout << "Test failed4" << endl;
            }
        }

        void testSpeedGrowApplied(){
            Field testField;
            // Sets the speedGrowApply to true.
            testField.setSpeedGrowApplied(true);
            // Checks to see if speedGrowApplied is set to true.
            if (testField.getSpeedGrowApplied() != true){
                    // Error message.
                    cout << "Test failed5" << endl;
            }

            // Sets the speedGrowApplied to false.
            testField.setSpeedGrowApplied(false);
            // Checks to see if speedGrowApplied is sets to true.
            if (testField.getSpeedGrowApplied() != false){
                // Error Message.
                cout << "Test failed6" << endl;
            }
        }
};

#endif
  