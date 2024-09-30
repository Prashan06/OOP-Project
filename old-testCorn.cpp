#include "testCorn.h"

Corn::Corn(){ // simply redefine the variables

cropPlantPrice = 10;

cropSellPrice = 100;

cropGrowth = 0.0;
 
cropGrowthRate = 1.0;

fertilizerPrice = 10; 
PesticidePrice = 10;     

fertilizerPercentage = 0.0;
pesticidePercentage = 0.0;

      int newMoney = getMoneyCount() - cropPlantPrice;
        setMoneyCount(newMoney);

}