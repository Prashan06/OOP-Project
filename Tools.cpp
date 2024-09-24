#include "Tools.h"
#include <iostream>

using namespace std;

void Tools::repair(){

    if (getMoneyCount() > 100){

        int newMoney = getMoneyCount() - 100;
        setMoneyCount(newMoney);
        repaired = true;

    }else{

        cout << "You do not currently have enough to pay for this repair" << endl;

    }

}