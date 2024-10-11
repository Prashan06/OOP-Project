void Farmer::upgradeCrop(){
    cout << "What crop would you like to upgrade, wheat or corn? (Enter response in lower case)" << endl;
    cin >> product;
    while (product != "wheat" && product != "corn") {
        cout << "invalid input! please enter wheat or corn" << endl;
        cin >> product;
    }

    if (product == "wheat"){
        string optionChoice;
        time_t currentTime = time(0); 
        int j = 0;
        int highYieldNotAppliedCount = 0;
        int newMoney = 0;
        for (int i = 0; i < wheatCount; ++i) {
            if (wheat[i]->getIsHighYieldApplied() == false) {
                newMoney = newMoney + wheat[i]->getHighYieldPrice();
                highYieldNotAppliedCount++;
            }
        }
        cout << "you have " << highYieldNotApplied << " wheat that are not upgraded " << newMoney <<" Would you like to upgrade them them (enter Y or N)" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == "Y") {
            for (int i = 0; i < wheatCount; ++i) {
                if ((currentTime - (wheat[i]->getTimer())) < wheat[i]->getSellTime()){
                    newWheatArray[j] = wheat[i];
                    j++;
                } else {
                    delete wheat[i];
                }
            }
            money = money + newMoney;
            wheat = newWheatArray;
            setWheatCount(wheatCount - readyToSellCount);
        }
        
    } else if (getProduct() == "corn") {
        string optionChoice;
        time_t currentTime = time(0); 
        int j = 0;
        int readyToSellCount = 0;
        int newMoney = 0;
        for (int i = 0; i < cornCount; ++i) {
            cout << "Yo" << endl;
            if (corn[i]->isReadyToSell() == true){
            newMoney = newMoney + corn[i]->getSellPrice();
            readyToSellCount++;
            }
        }
        Corn** newCornArray = new Corn*[cornCount - readyToSellCount];
        cout << "you have " << readyToSellCount << " corn to sell for " << newMoney <<" Would you like to sell them (enter Y or N)" << endl;
        cin >> optionChoice;
        while (optionChoice != "Y" && optionChoice != "N") {
            cout << "invalid input! please enter Y or N" << endl;
            cin >> optionChoice;
        }
        if (optionChoice == "Y") {
            for (int i = 0; i < cornCount-1; ++i) {
                if (corn[i]->isReadyToSell() == false){
                newCornArray[j++] = corn[i];
                }
            }
            money = money + newMoney;
            corn = newCornArray;
            setCornCount(cornCount - readyToSellCount);
        }
    }
}