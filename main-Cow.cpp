#include <iostream>
#include <ctime>
#include "Cows.h"

// this file is going to test the Cow class to check that the functions specifically in Cow are acting as they are intended to
// even though barn contains other inherited functions, they will not be tested as these functions will be tested in the file testing
// the class in which the other functions are defined. 
// the functions in this specific case are setMaxCapacity(int maxCapacity), increaseBarnCapacity(), setCowCount(int cowCount),
// getCowCount(), buyItem(), sellItem(), getNumberOfTimesCowsAreBought(), setNumberOfTimesCowsAreBought(int numberOfTimesCowsAreBought), 
// getTimeArray(), getCowArray(), and ~Cows().

int main () {
    Cows c;
    c.setMoneyCount(10000); // setting a large money count so that the functions being tested can operate propley wihout worry of running out of money
    c.setMaxAnimalCapacity(15); // realistic case, should print Max cow capacity is: 15.
    c.setMaxAnimalCapacity(9); // boundary case, should print error message. although 9 is a positive number, it is less than the default 
                               // size 10, and since max capacity never decreases, any paramter less than 10 should be invalid
    c.increaseBarnCapacity(); // should increase the maximum barn capacity from 15 to 20
    cout << c.getMoneyCount() << endl; // checking that the money was reduced by 15 dollars

    c.setCowCount(15); // should set CowCount to 15
    cout << c.getCowCount() << endl; // should print 15
    c.setCowCount(-25); // should print error message.

    c.buyItem(); // should run user through the process to buy cows.

    c.buyItem(); // running through buying process again so that cow and time arrays are larger than 1 element

    int blocker; // method used in test to allow for some time to pass inbetween buying and printing array values to test that time is being incremented correctly
    cout << "enter number" << endl;
    cin >> blocker;

    for (int i = 0; i < c.getNumberOfTimesCowsAreBought(); i++){ // method to test the allocation of cow and time values are correct
        cout << c.getCowArray()[i] << endl;
        cout << c.getTimeArray()[i] << endl;
    }

    cout << "enter number" << endl; // method used in test to allow for some time to pass inbetween buying and selling cows.
    cin >> blocker;

    c.sellItem(); // should run user through the process to sell cows. 

    for (int j = 0; j < c.getNumberOfTimesCowsAreBought(); j++){ // method to test that both cow and time arrays are resized correctly 
        cout << c.getCowArray()[j] << endl;
        cout << c.getTimeArray()[j] << endl;
    }

    return 0;
}