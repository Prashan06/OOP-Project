#ifndef UNITTESTFARM_H
#define UNITTESTFARM_H

#include "Farm.h"

using namespace std;

class unitTestFarm {
 protected:
  // This function will test the functions in Farm.
  void testFarm() {
    Farm f;
    // Sets BuyPrice to 10
    f.setBuyPrice(10);
    // Error message if BuyPrice is not equal to 10
    if (f.getBuyPrice() != 10) {
      cout << "Buy price failed. " << endl;
    }
    // Sets sellPrice to 10
    f.setSellPrice(10);
    // Error message if sellPrice is not equal to 10.
    if (f.getSellPrice() != 10) {
      cout << "Sell price failed. " << endl;
    }
    // Sets sellTime to 10.
    f.setSellTime(10);
    // If sellTime if not equal to 10, output a error message.
    if (f.getSellTime() != 10) {
      cout << "Sell time failed. " << endl;
    }
    cout << "Timer is: " << f.getTimer() << endl;
  }

 public:
  // Run the tests above.
  void runTests() { testFarm(); }
};

#endif