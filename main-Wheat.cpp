#include <iostream>
#include <ctime>
#include "Wheat.h"

using namespace std;

/* This file will test the Wheat class to check if the functions in this class are working as expected.
this test will only test functions in the Wheat class and not any inherited functions as they are tested
in other files.*/

int main () {
    Wheat w;
    w.setMoneyCount(10000); 
    w.setMaxCropsCapacity(15); // realistic case, should print Max wheat capacity is: 15.
    w.setMaxCropsCapacity(9); // Boundry case, although 9 is a positive numbers, it is less than default, thus an error message should be printed.
    w.increaseFieldCapacity(); // should increase the maximum field capacity from 15 to 20
    cout << w.getMoneyCount() << endl; // checking that the money was reduced by 8 dollars

    w.setWheatCount(10); // should set wheatcount to 10.
    cout << w.getWheatCount() << endl; // should print 10
    w.setWheatCount(-25); // should print error message.

    w.setNumberOfTimesWheatAreBought(4);
    cout << "number of times wheat are bought: " << w.getNumberOfTimesWheatAreBought() << endl;
    w.setNumberOfTimesWheatAreBought(0);
    cout << "number of times wheat are bought: " << w.getNumberOfTimesWheatAreBought() << endl;

    w.buyItem(); // should run user through the process to buy wheat.

    w.buyItem(); // running through buying process again so that the wheat and time arrays are larger than 1 element

    cout << "number of times wheat are bought: " << w.getNumberOfTimesWheatAreBought() << endl; // should print number or times wheat have been bought.

    int blocker; // method used in test to allow for some time to pass inbetween buying and printing array values to test that time is being incremented correctly
    cout << "enter number" << endl;
    cin >> blocker;

    for (int i = 0; i < w.getNumberOfTimesWheatAreBought(); i++){ // method to test the allocation of wheat and time values are correct
        cout << w.getWheatArray()[i] << endl;
        cout << w.getTimeArray()[i] << endl;
    }

    cout << "enter number" << endl; // method used in test to allow for some time to pass inbetween buying and selling wheat.
    cin >> blocker;

    w.sellItem(); // should run user through the process to sell wheat. 

    for (int j = 0; j < w.getNumberOfTimesWheatAreBought(); j++){ // method to test that both wheat and time arrays are resized correctly 
        cout << w.getWheatArray()[j] << endl;
        cout << w.getTimeArray()[j] << endl;
    }

    cout << "number of times wheat are bought: " << w.getNumberOfTimesWheatAreBought() << endl; // should print message then 0 if all wheat are sold, 
                                                                                              //should print message then 1 if only first batch of wheat are sold

    return 0;
}