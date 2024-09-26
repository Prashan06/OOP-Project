#include <iostream>
#include "Barn.h"

using namespace std;

// this file is going to test the barn class to check that the functions specifically in barn are acting as they are intended to
// even though barn contains other inherited functions, they will not be tested as these functions will be tested in the file testing
// the class in which the other functions are defined. 
// the functions in this specific case are setAnimalCount() and getAnimalCount() 

int main(){
    Barn b;
    b.setAnimalCount(20, 30); // should set animal count to 50
    cout << b.getAnimalCount() << endl; // should print 50, indicating a successful test
    b.setAnimalCount(1000, 100000000); // extreme case - unlikely to occur in final program, however should still print 100001000
    cout << b.getAnimalCount() << endl; // 100001000
    b.setAnimalCount(-2, 30); // should print out error message as negatie paramters do not make sense in the context of the final program
    return 0;
}

// after compiling and running the program, the output is as expected