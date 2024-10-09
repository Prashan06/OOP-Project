#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Corn{

    protected:

        int cornNumber = 1;

    public:

        int getCornNumber(){
            return cornNumber;
        }
        void setCornNumber(int cornNumber){
            this->cornNumber = cornNumber;
        }

};

int main() {

    std::vector<Corn> cornArray;

    Corn c1;
    Corn c2;
    Corn c3;

    int cornNumber = 2;
    c3.setCornNumber(cornNumber);

    cornArray.push_back(c1);
    cornArray.push_back(c2);
    cornArray.push_back(c3);

    for (int i = 0; i < cornArray.size(); i++){
        cout << " " << cornArray[i].getCornNumber() << endl;
    }

    cout << " " << endl;

     for (int i = 0; i < cornArray.size(); i++){
        if (cornArray[i].getCornNumber() == 2){
        cornArray.erase(cornArray.begin() + i);
        }
    }

   for (int i = 0; i < cornArray.size(); i++){
        cout << " " << cornArray[i].getCornNumber() << endl;
    }

    return 0;
}
