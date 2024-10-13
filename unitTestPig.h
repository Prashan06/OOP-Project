#ifndef UNITTESTPIG_H
#define UNITTESTPIG_H

#include "Pig.h"
#include "Events.h"
 
using namespace std;

class unitTestPig{

    public:

    void testPig(){
        // execute functions below.
        testConstructor();
        testApplyHighYield();
        testEvent();
    }

    protected:
    // Test the constructor.
        void testConstructor(){
            Pig pig;
            // Call the constructor and verify that the values are constructed to the correct setting.
            if (pig.getSellPrice() != 15 && pig.getBuyPrice() != 12 && pig.getSellTime() == 12 && pig.getHighYieldPrice() == 15){
                cout << "Constructor test failed" << endl;
            }
        }

        // Test the applyHighYield
        void testApplyHighYield(){
            Pig pig;
            // Set money to 20.
            int Money = 20;
            int* MoneyCountPtr = &Money;
             // Take money as a parameter and execute applyHighYieldFunction.
            pig.applyHighYield(MoneyCountPtr);
            // If statement to check if pigHighYieldApplied is true and money has decreased. 
            if (pig.getPigHighYieldApplied() != true && Money != 5){
            cout << "applyHighYield test failed. " << endl;
            }
        }

        // Test the event function
        void testEvent(){
            Pig pig;
            // Set the number of pigs to 10.
            int pigCount = 10;
            int* pigCountPtr = &pigCount;
            // Set the pigEvent variable to false.
            pig.setPigEvent(false);
            // Execute the event function with wheatCount taken as a variable.
            pig.Event(pigCountPtr);
            cout << " "  << pig.getPigEvent() << endl;
            // if statement to check if function worked as expected. 
            // Note that when random num gen taken out, below works. Otherwise, pig event is true at random times which is correct.
            if (pig.getPigEvent() != true){
                cout << "Pig Event - Event failed. " << endl;
            } 
        }
};

#endif