#include <iostream>
#include <ctime>
#include "Cows.h"

// this file is going to test the Cow class to check that the functions specifically in Cow are acting as they are intended to
// even though barn contains other inherited functions, they will not be tested as these functions will be tested in the file testing
// the class in which the other functions are defined. 
// the functions in this specific case are setMaxCapacity(int maxCapacity), increaseBarnCapacity(), setCowCount(int cowCount),
// getCowCount(), buyItem(), sellItem(), getNumberOfTimesCowsAreBought(), setNumberOfTimesCowsAreBought(int numberOfTimesCowsAreBought), 
// getTimeArray(), getCowArray().

int main () {
    Cows c;
    c.setMaxAnimalCapacity(15); // realistic case, should print Max cow capacity is: 15.
    c.setMaxAnimalCapacity(-20); // boundary case, shoulld print error message.
    
    return 0;
}