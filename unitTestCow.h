#ifndef UNITTESTCow_H
#define UNITTESTCow_H

#include "Cow.h"
#include "Events.h"
#include "Farmer.h"

using namespace std;

class unitTestCow {
 public:
  void testCow() {
    // execute functions below.
    testConstructor();
    testApplyHighYield();
    testEvent();
  }

 protected:
  // Test the constructor.
  void testConstructor() {
    Cow cow;
    // Call the constructor and verify that the values are constructed to the
    // correct setting.
    if (cow.getSellPrice() != 18 && cow.getBuyPrice() != 15 &&
        cow.getSellTime() == 15) {
      // Display error message.
      cout << "Constructor test failed" << endl;
    }
  }

  // Test the applyHighYield
  void testApplyHighYield() {
    Cow cow;
    // Set money to 30.
    int Money = 30;
    int* MoneyCountPtr = &Money;
    // Take money as a parameter and execute applyHighYieldFunction.
    cow.applyHighYield(MoneyCountPtr);
    // If statement to check if cowHighYieldApplied is true and money has
    // decreased.
    if (cow.getCowHighYieldApplied() != true && Money != 5) {
      cout << "applyHighYield test failed. " << endl;
    }
  }

  // Test the event function
  void testEvent() {
    Cow cow;
    // Set number of cows to 10
    int cowCount = 10;
    int* cowCountPtr = &cowCount;
    // set cowEvent to false.
    cow.setCowEvent(false);
    // Execute the event function with wheatCount taken as a variable.
    cow.Event(cowCountPtr);
    cout << " " << cow.getCowEvent() << endl;
    // if statement to check if function worked as expected.
    // Note that when random num gen taken out, below works. Otherwise, cow
    // event is true at random times which is correct.
    if (cow.getCowEvent() != true) {
      cout << "Cow Event - Event failed. " << endl;
    }
  }
};

#endif