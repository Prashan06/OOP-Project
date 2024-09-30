#ifndef testFARMER_H
#define testFARMER_H

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

#include "testFarm.h"

using namespace std;

class Farmer {

        protected:

        int Money;
        
        int DayLength;
        int DayCount = 0;
        time_t startTime;

        test

    public:

        Farmer();
        int nextDay();
        int getMoneyCount();
        void setMoneyCount(int Money);
        void getStatus();
        void setFarmName();
        std::string getFarmName();
        int getDayCount();
        int getDayLength();

};

#endif