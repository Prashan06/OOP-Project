#include <iostream>
#include <ctime>
#include "Pigs.h"

// this file is going to test the Pigs class to check that the functions specifically in Pigs are acting as they are intended to
// even though Pigs contains other inherited functions, they will not be tested as these functions will be tested in the file testing
// the class in which the other functions are defined. 
// the functions in this specific case are setMaxCapacity(int maxCapacity), increaseBarnCapacity(), setPigCount(int pigCount),
// getPigCount(), buyItem(), sellItem(), getNumberOfTimesPigsAreBought(), setNumberOfTimesPigsAreBought(int numberOfTimesPigsAreBought), 
// getTimeArray(), and getPigArray().

int main () {
    Pigs p;
    p.setMoneyCount(10000); // setting a large money count so that the functions being tested can operate propley wihout worry of running out of money
    p.setMaxAnimalCapacity(15); // realistic case, should print Max pig capacity is: 15.
    p.setMaxAnimalCapacity(9); // boundary case, should print error message. although 9 is a positive number, it is less than the default 
                               // size 10, and since max capacity never decreases, any paramter less than 10 should be invalid
    p.increaseBarnCapacity(); // should increase the maximum barn capacity from 15 to 20
    cout << p.getMoneyCount() << endl; // checking that the money was reduced by 15 dollars

    p.setPigCount(10); // should set pigCount to 15
    cout << p.getPigCount() << endl; // should print 15
    p.setPigCount(-25); // should print error message.

    p.setNumberOfTimesPigsAreBought(4);
    cout << "number of times pigs are bought: " << p.getNumberOfTimesPigsAreBought() << endl;
    p.setNumberOfTimesPigsAreBought(0);
    cout << "number of times pigs are bought: " << p.getNumberOfTimesPigsAreBought() << endl;

    p.buyItem(); // should run user through the process to buy pigs.

    p.buyItem(); // running through buying process again so that the pig and time arrays are larger than 1 element

    cout << "number of times pigs are bought: " << p.getNumberOfTimesPigsAreBought() << endl; // should print number or times pigs have been bought: 2

    int blocker; // method used in test to allow for some time to pass inbetween buying and printing array values to test that time is being incremented correctly
    cout << "enter number" << endl;
    cin >> blocker;

    for (int i = 0; i < p.getNumberOfTimesPigsAreBought(); i++){ // method to test the allocation of pig and time values are correct
        cout << p.getPigArray()[i] << endl;
        cout << p.getTimeArray()[i] << endl;
    }

    cout << "enter number" << endl; // method used in test to allow for some time to pass inbetween buying and selling pigs.
    cin >> blocker;

    p.sellItem(); // should run user through the process to sell pigs. 

    for (int j = 0; j < p.getNumberOfTimesPigsAreBought(); j++){ // method to test that both pig and time arrays are resized correctly 
        cout << p.getPigArray()[j] << endl;
        cout << p.getTimeArray()[j] << endl;
    }

    cout << "number of times pigs are bought: " << p.getNumberOfTimesPigsAreBought() << endl; // should print message then 0 if all cows are sold, 
                                                                                              //should print message then 1 if only first batch of cows are sold

    return 0;
}