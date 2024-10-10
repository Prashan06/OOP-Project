#include <iostream>
#include <string>

using namespace std;

class Corn {
protected:
    int cornNumber;

public:
    Corn(int cornNumber) : cornNumber(cornNumber) {}
    
    void setCornNumber(int cornNumber) {
        this->cornNumber = cornNumber;
    }
    
    int getCornNumber() {
        return cornNumber;
    }
};

void buyCorn(Corn**& cornArray, int& cornArraySize, int& cornCount) {
    Corn** newCornArray = new Corn*[cornArraySize + 1];
    for (int i = 0; i < cornArraySize; ++i) {
        newCornArray[i] = cornArray[i];
    }

    Corn* newCorn = new Corn(cornCount++);
    newCornArray[cornArraySize] = newCorn;

    delete[] cornArray;
    cornArray = newCornArray;
    ++cornArraySize;
}

<<<<<<< HEAD
void sellCorn(Corn**& cornArray, int& cornCount, int *money) {
    int jo;
=======
void sellCorn(Corn**& cornArray, int& cornCount, int& money}
    int option;
>>>>>>> f9f71f765b900888cc7a3691324df26333b8aece
    int j = 0;
    int readyToSellCount = 0;
    int newMoney = 0;
    for (int i = 0; i < cornCount; ++i) {
        if (corn[i]->getTimer() >= corn[i]->getSellTime()){
        newMoney = newMoney + corn[i]->getSellPrice();
        readyToSellCount++;
        }
    }
    Corn** newCornArray = new Corn*[cornCount - readyToSellCount];
    cout << "you have " << readyToSellCount << "corn to sell for " << newMoney <<" Press 1 to confirm" << endl;
    cin >> option;
    switch(option){
    case 1:
        for (int i = 0; i < cornArraySize; ++i) {
            if (corn[i]->getTimer() < corn[i]->getSellTime()){
            newCornArray[j++] = cornArray[i];
            }
        }
        money = money + newMoney;

        delete[] cornArray;
        cornArray = newCornArray;
        cornArraySize - readyToSellCount;
        break;
        
    case 2:
        break;
    default:
        break;
    }
}

int main() {

    int cornCount = 1;
    int cornArraySize = 0;
    Corn** cornArray = new Corn*[cornArraySize];

    buyCorn(cornArray, cornArraySize, cornCount);
    buyCorn(cornArray, cornArraySize, cornCount);
    buyCorn(cornArray, cornArraySize, cornCount);
    buyCorn(cornArray, cornArraySize, cornCount);
    buyCorn(cornArray, cornArraySize, cornCount);
    buyCorn(cornArray, cornArraySize, cornCount);

    sellCorn(cornArray, cornArraySize, cornCount, 3);
    sellCorn(cornArray, cornArraySize, cornCount, 1);

    for (int i = 0; i < cornArraySize; ++i){
        cout << "Corn number: " << cornArray[i]->getCornNumber() << endl;
    }

    cout << "The size of the corn array is now " << cornArraySize << endl;

 
    while (1){
        int option = 0;
        cout << "If you want to buy corn press 3, if you want to sell corn press 4" << endl;
        cin >> option;

        while (option == 3){
            int option2 = 0;
            cout << "To confirm buy press 5, to leave press 6" << endl;
            cin >> option2;
            if (option2 == 5){
            buyCorn(cornArray, cornArraySize, cornCount);
            for (int i = 0; i < cornArraySize; ++i){
            cout << "Corn number: " << cornArray[i]->getCornNumber() << endl;
            }
            } else if (option2 == 6){
                option = 0;
            }
        }

        while (option == 4){
            int option3 = 0;
            cout << "To confirm sell press 7, to leave press 8" << endl;
            cin >> option3;
            if (option3 == 7){
            int cornNumToSell = 0;
            cout << "Enter number of corn you want to sell" << endl;
            cin >> cornNumToSell;
            sellCorn(cornArray, cornArraySize, cornCount, cornNumToSell);

            } else if (option3 == 8){
                option = 0;
            }
        }

   for (int i = 0; i < cornArraySize; ++i) {
        delete cornArray[i];
    }
    delete[] cornArray;

}
}




