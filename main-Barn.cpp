#include "Farmer.h"

using namespace std;

int main(){
    Farmer F;

    cout << "" << F.getMoneyCount() << endl;
    F.setMoneyCount(200);
    cout << "" << F.getMoneyCount() << endl;    
    F.setFarmName();
    F.getStatus();
    F.getDayCount();
    cout << "" << F.getFarmName() << endl;
    return 0;
}