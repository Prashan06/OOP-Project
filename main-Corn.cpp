#include <iostream>
#include <ctime>
#include "Corn.h"

using namespace std;

/* This file will test the Corn class to check if the functions in this class are working as expected.
this test will only test functions in the Corn class and not any inherited functions as they are tested
in other files.*/

int main () {
    Corn c;
    c.setMoneyCount(10000); 
    c.setMaxCropCapacity(15); // realistic case, should print Max corn capacity is: 15.
    c.setMaxCropCapacity(9); // Boundry case, although 9 is a positive numbers, it is less than default, thus an error message should be printed.
    c.increaseFieldCapacity(); // should increase the maximum field capacity from 15 to 20
    cout << c.getMoneyCount() << endl; // checking that the money was reduced by 8 dollars

    c.setCornCount(10); // should set wheatcount to 10.
    cout << c.getCornCount() << endl; // should print 10
    c.setCornCount(-25); // should print error message.

    c.setNumberOfTimesCornIsBought(4);
    cout << "number of times corn are bought: " << c.getNumberOfTimesCornIsBought() << endl;
    c.setNumberOfTimesCornIsBought(0);
    cout << "number of times corn are bought: " << c.getNumberOfTimesCornIsBought() << endl;

    c.buyItem(); // should run user through the process to buy corn.

    c.buyItem(); // running through buying process again so that the corn and time arrays are larger than 1 element

    cout << "number of times corn are bought: " << c.getNumberOfTimesCornIsBought() << endl; // should print number or times corn have been bought.

    int blocker; // method used in test to allow for some time to pass inbetween buying and printing array values to test that time is being incremented correctly
    cout << "enter number" << endl;
    cin >> blocker;

    for (int i = 0; i < c.getNumberOfTimesCornIsBought(); i++){ // method to test the allocation of wheat and time values are correct
        cout << c.getCornArray()[i] << endl;
        cout << c.getTimeArray()[i] << endl;
    }

    cout << "enter number" << endl; // method used in test to allow for some time to pass inbetween buying and selling wheat.
    cin >> blocker;

    c.sellItem(); // should run user through the process to sell wheat. 

    for (int j = 0; j < c.getNumberOfTimesCornIsBought(); j++){ // method to test that both corn and time arrays are resized correctly 
        cout << c.getCornArray()[j] << endl;
        cout << c.getTimeArray()[j] << endl;
    }

    cout << "number of times corn are bought: " << c.getNumberOfTimesCornIsBought() << endl; // should print message then 0 if all corn are sold, 
                                                                                              //should print message then 1 if only first batch of corn are sold

    return 0;
}