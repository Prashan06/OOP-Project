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

};

int main() {

    std::vector<Corn> cornArray;

    Corn c1;
    Corn c2;
    Corn c3;

    cornArray.push_back(c1);
    cornArray.push_back(c2);
    cornArray.push_back(c3);

    for (int i = 0; i < cornArray.size(); i++){
        cout << " " << endl;
        cout << cornArray[i].getCornNumber() << endl;
    }

    cornArray.pop_back();

   for (int i = 0; i < cornArray.size(); i++){
        cout << " " << endl;
        cout << cornArray[i].getCornNumber() << endl;
    }

    return 0;
}
