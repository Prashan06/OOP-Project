#include "Field.h"

Field::Field() : Farm(), wheatCount(0), cornCount(0),wheatGrowthRate(0), cornGrowthRate(0), cropCount(0), fertiliserTimer(0), PesticideTimer(0){}


int Field::getCropCount(){
    cropCount = wheatCount + cornCount;
    return cropCount;
}

void Field::setCropCount(int wheatCount, int cornCount){
    cropCount = wheatCount + cornCount;
} 

int Field::increaseMaxFieldCapacity(){}
void Field::setMaxFieldCapacity(){}

void Field::Fertilisation(){
    std::cout << "Would you like to buy fertilizer? Y or N" << std::endl;
    std::cin >> optionChoice;
        if (optionChoice == "Y"){
            std::cout << "Fertilisation has begun" << std::endl;
            fertiliserTimer = time(0);
            while (fertiliserTimer <= 360){
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