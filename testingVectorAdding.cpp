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

void sellCorn(Corn**& cornArray, int& cornArraySize, int& cornCount, int numRemove) {
    Corn** newCornArray = new Corn*[cornArraySize - 1];
    int j = 0;
    for (int i = 0; i < cornArraySize; ++i) {
        if (cornArray[i]->getCornNumber() != numRemove){
        newCornArray[j++] = cornArray[i];
        }
    }

    delete[] cornArray;
    cornArray = newCornArray;
    --cornArraySize;
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
        int option;
        cout << "If you want to buy corn press 3, if you want to sell corn press 4" << endl;
        cin >> option;
        if (option == 3){
            buyCorn(cornArray, cornArraySize, cornCount);
            for (int i = 0; i < cornArraySize; ++i){
            cout << "Corn number: " << cornArray[i]->getCornNumber() << endl;
            }
        }else if (option == 4){
            int cornNumToSell = 0;
            for (int i = 0; i < cornArraySize; ++i){
            cout << "Corn number: " << cornArray[i]->getCornNumber() << endl;
            }
            cout << "Enter number of corn you want to sell" << endl;
            cin >> cornNumToSell;
            sellCorn(cornArray, cornArraySize, cornCount, cornNumToSell);
            
        }
    }


   for (int i = 0; i < cornArraySize; ++i) {
        delete cornArray[i];
    }
    delete[] cornArray;

}




