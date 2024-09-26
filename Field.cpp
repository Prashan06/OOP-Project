#include "Field.h"

Field::Field() : Farm(), wheatCount(0), cornCount(0), wheatGrowthRate(0), cornGrowthRate(0), cropCount(0), fertiliserTimer(0), PesticideTimer(0), fertiliserDuration(3){}


int Field::getCropCount(){
    cropCount = wheatCount + cornCount;
    return cropCount;
}

void Field::setCropCount(int wheatCount, int cornCount){
    cropCount = wheatCount + cornCount;
} 

void Field::increaseMaxFieldCapacity(){}
void Field::setMaxFieldCapacity(){}

void Field::Fertilisation(){
    std::cout << "Would you like to buy fertilizer? Y or N" << std::endl;
    std::cin >> optionChoice;
        if (optionChoice == "Y"){
            std::cout << "Fertilisation has begun" << std::endl;
            setMoneyCount(Money - 50);
            fertiliserTimer = time(0);
            dayCount = (fertiliserTimer - time(NULL))/60;
            while ( dayCount <= fertiliserDuration ){
                wheatGrowthRate--;
                cornGrowthRate--;
            }
            if (fertiliserTimer > 360){
                fertiliserTimer = 0;
                wheatGrowthRate = 15;
                cornGrowthRate = 20;
            }
        }
}