#include "Field.h"

Field::Field() : Farm(), wheatCount(0), cornCount(0), wheatGrowthRate(0), cornGrowthRate(0), cropCount(0), fertiliserTimer(0), PesticideTimer(0), fertiliserDuration(360), elapsedTime(0){}


int Field::getCropCount(){
    cropCount = wheatCount + cornCount;
    return cropCount;
}

void Field::setCropCount(int wheatCount, int cornCount){
    this -> wheatCount  =wheatCount;
    this -> cornCount = cornCount;
    cropCount = this-> wheatCount + this-> cornCount;
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
            double elapsedTime = 0;
            while ( elapsedTime <= fertiliserDuration ){
                elapsedTime = time(NULL) - fertiliserTimer;

                if (elapsedTime < fertiliserDuration) break;

                wheatGrowthRate = 5 ;
                cornGrowthRate = 10;

                std::cout << "Wheat Growth Rate is: " << wheatGrowthRate <<std::endl;
                std::cout << "Corn Growth Rate is: " << cornGrowthRate <<std::endl;
            }

                fertiliserTimer = 0;
                wheatGrowthRate = 15;
                std::cout << "Wheat Growth Rate is: " << wheatGrowthRate<<std::endl;
                cornGrowthRate = 20;
                std::cout << "Corn Growth Rate is: " << cornGrowthRate <<std::endl;
        }
}

void Field:: sellItem(){}

void Field::buyItem(){}