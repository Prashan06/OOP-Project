#ifndef UNITTESTBARN_H
#define UNITTESTBARN_H

#include "Barn.h"

using namespace std;

class unitTestBarn{

    public:

    void testBarn(){
        // Execute functions below.
        testHighYield();
        testSpeedGrowPrice();
        testSpeedGrowApplied();
    }

    protected:
        void testHighYield(){
            Barn testBarn;
            // Set the highYieldFactor to 1.2.
            testBarn.setHighYieldFactor(1.2);
            // Check if getHighYieldFactor() works as expected.
            if (testBarn.getHighYieldFactor() != 1.2){
                // Error message.
                cout << "Test failed" << endl;
            }

            // Set the highYieldFactor to 2.
            testBarn.setHighYieldPrice(2);
            // Check if getHighYieldFactor() works as expected.
            if (testBarn.getHighYieldPrice() != 2){
                // Error message. 
                    cout << "Test failed" << endl;
            }
        }

        void testSpeedGrowPrice(){
            Barn testBarn;
            // setSpeedGrowPrice to 2.
            testBarn.setSpeedGrowPrice(2);
            // Check if setSpeedGrowPrice sets the speedGrowPrice variable to 2.
            if (testBarn.getSpeedGrowPrice() != 2){
                // error message.
                cout << "Test failed" << endl;
            }           
        }

        void testSpeedGrowLevel(){
            Barn testBarn;
            //Set speedGrowLevel to 10; 
            testBarn.setSpeedGrowLevel(10);
            // Check if setSpeedGrowPrice sets the speedGrowPrice variable to 10.
            if (testBarn.getSpeedGrowLevel() != 10){
                // Error message.
                cout << "Test failed" << endl;
            }
        }

        void testSpeedGrowApplied(){
            Barn testBarn;
            // Sets the speedGrowApply to true.
            testBarn.setSpeedGrowApplied(true);
            // Checks to see if speedGrowApplied is set to true.
            if (testBarn.getSpeedGrowApplied() != true){
                    // Error message.
                    cout << "Test failed" << endl;
            }

            // Sets the speedGrowApplied to false.
            testBarn.setSpeedGrowApplied(false);
            // Checks to see if speedGrowApplied is sets to true.
            if (testBarn.getSpeedGrowApplied() != false){
                // Error Message.
                cout << "Test failed" << endl;
            }
        }
};

#endif