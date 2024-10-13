#ifndef UNITTESTWHEAT_H
#define UNITTESTWHEAT_H

#include "Wheat.h"
#include "Farmer.h"
#include "Events.h"
 
using namespace std;

class unitTestWheat{

    public:

    void testWheat(){
        // execute functions below.
        testConstructor();
        testApplyHighYield();
        testEvent();
    }

    protected:
    // Test the constructor.
        void testConstructor(){
            Wheat wheat;
            // Call the constructor and verify that the values are constructed to the correct setting.
            if (wheat.getSellPrice() != 15 && wheat.getBuyPrice() != 10 && wheat.getSellTime() == 8 && wheat.getHighYieldPrice() == 10){
                // Display error message.
                cout << "Constructor test failed" << endl;
            }
        }

        // Test the applyHighYield
        void testApplyHighYield(){
            Wheat wheat;
            // Set money to 20.
            int Money = 20;
            int* MoneyCountPtr = &Money;
            // Take money as a parameter and execute applyHighYieldFunction.
            wheat.applyHighYield(MoneyCountPtr);
            // If statement to check if wheatHighYieldApplied is true and money has decreased. 
            if (wheat.getWheatHighYieldApplied() != true && Money != 10){
                // Error message. 
            cout << "applyHighYield test failed. " << endl;
            }
        }

        // Test the event function
        void testEvent(){
            Wheat wheat;
            // Set the number of wheats to 10.
            int wheatCount = 10;
            int* wheatCountPtr = &wheatCount;
            // Set the wheatEvent variable to false.
            wheat.setWheatEvent(false);
            // Execute the event function with wheatCount taken as a variable.
            wheat.Event(wheatCountPtr);
            cout << " "  << wheat.getWheatEvent() << endl;
            // if statement to check if function worked as expected. 
            // Note that when random num gen taken out, below works. Otherwise, wheat event is true at random times which is correct.
            if (wheat.getWheatEvent() != true){
                // Error message
                cout << "Wheat Event - Event failed. " << endl;
            } 
        }
};

#endif