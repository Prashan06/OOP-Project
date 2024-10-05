#ifndef UNITTESTFARM_H
#define UNITTESTFARM_H

#include "Farm.h"
 
using namespace std;

class unitTestFarm{
    protected:
    void testFarm(){
        Farm f;
        f.setBuyPrice(10);
        if (f.getBuyPrice() != 10){
            cout << "Buy price failed. " << endl;
        }
        f.setSellPrice(10);
        if (f.getSellPrice() != 10){
            cout << "Sell price failed. " << endl;
        }  
        f.setSellTime(10);  
        if (f.getSellTime() != 10){
            cout << "Sell time failed. " << endl;
        }  
        cout << "Timer is: " <<f.getTimer() << endl;
    }
    public:
    void runTests(){
        testFarm();
    }

};


#endif