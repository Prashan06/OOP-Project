#include "testField.h"
        
Field::Field(){

cropPlantPrice = 10;

cropSellPrice = 100;

cropGrowth = 0.0;
 
cropGrowthRate = 1.0;

fertilizerPrice = 10; 
PesticidePrice = 10;     

fertilizerPercentage = 0.0;
pesticidePercentage = 0.0;

}

void Field::Fertilzation(){

        if (getMoneyCount() > fertilizerPrice){
        int newMoney = getMoneyCount() - fertilizerPrice;
        setMoneyCount(newMoney);
        fertilizerPercentage = 100.0;

    }else{
        cout << "You do not currently have enough to buy this fertilizer" << endl;
    }

}

void Field::Pesticide(){

     if (getMoneyCount() > pesticidePrice){
        int newMoney = getMoneyCount() - pesticidePrice;
        setMoneyCount(newMoney);
        pesticidePercentage = 100.0;

    }else{
        cout << "You do not currently have enough to buy this pesticide" << endl;
    }

}

void Field::Grow(){

    cropGrowth = cropGrowth + (cropGrowthRate * pesticidePercentage * fertilizerPercentage);

} 

int Field::sellItem(){

        int newMoney = getMoneyCount() - pesticidePrice;
        setMoneyCount(newMoney);

}