#include "testField.h"
        
Field::Field(){

cropPlantPrice = 10;

cropSellPrice = 100;

cropGrowth = 0.0;
 
cropGrowthRate = 1.0;

fertilizerPrice = 10; 
PesticidePrice = 10;     

fertilizerPercentage = 0.75;
pesticidePercentage = 0.0;

      int newMoney = getMoneyCount() - cropPlantPrice;
        setMoneyCount(newMoney);

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

    cropGrowth = cropGrowth + (cropGrowthRate * fertilizerPercentage);

    if (cropGrowth >= 100.0){
        cropGrowth = 100.0;

        cout << "Field is ready to be harvested" << endl;

    }

} 

int Field::sellItem(){

    if (isPlanted == true){

        int amountReceived = cropGrowth*cropSellPrice;

        int newMoney = getMoneyCount() + amountReceived;
        setMoneyCount(newMoney);

        //updating variables
        isPlanted = false;
        fertilizerPercentage = 0.0;
        pesticidePercentage = 0.0;
        cropGrowth = 0.0;

        cout << "You received: " << soldPrice << endl;

    }else{

        cout << "Field is not planted" << endl;

    }


}

void Field::plant(){

    if (isPlanted == false){

        if (getMoneyCount()>cropPlantPrice){

            isPlanted = true;

             int newMoney = getMoneyCount() - cropPlantPrice;
             setMoneyCount(newMoney);

        }else{

            cout << "You do not have enough money to plant this field" << endl;

        }

    }else{

        cout << "Field is already planted" << endl;

    }

}