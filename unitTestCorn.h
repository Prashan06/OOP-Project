#ifndef UNITTESTCORN_H
#define UNITTESTCORN_H

#include "Corn.h"
#include "Farmer.h"
#include "Events.h"
 
using namespace std;

class unitTestCorn{

    public:

    void testCorn(){
        // execute functions below.
        testConstructor();
        testApplyHighYield();
        testEvent();
    }

    protected:
        // Test the constructor.
        void testConstructor(){
            Corn corn;
            // Call the constructor and verify that the values are constructed to the correct setting.
            if (corn.getSellPrice() != 15 && corn.getBuyPrice() != 13 && corn.getSellTime() == 5 && corn.getHighYieldPrice() == 19){
                // Display error message.
                cout << "Constructor test failed" << endl;
            }
        }
        
        // Test the applyHighYield
        void testApplyHighYield(){
            Corn corn;
            // Set money to 20.
            int Money = 20;
            int* MoneyCountPtr = &Money;
            // Take money as a parameter and execute applyHighYieldFunction.
            corn.setCornHighYieldApplied(false);
            corn.applyHighYield(MoneyCountPtr);
            // If statement to check if cornHighYieldApplied is true and money has decreased.
            if (corn.getCornHighYieldApplied() != true && Money != 5){
            cout << "applyHighYield test failed. " << endl;
            }
        }

        // Test the event function
        void testEvent(){
            Corn corn;
            // Set the number of corn to 10.
            int cornCount = 10;
            int* cornCountPtr = &cornCount;
            // Set the cornEvent variable to false.
            corn.setCornEvent(false);
            // Execute the event function with cornCount taken as a variable.
            corn.Event(cornCountPtr);
            cout << " "  << corn.getCornEvent() << endl;
            // if statement to check if function worked as expected. 
             // Note that when random num gen taken out, below works. Otherwise, pig event is true at random times which is correct.           
            if (corn.getCornEvent() != true){
                cout << "corn Event - Event failed. " << endl;
            } 
        }
};

#endif