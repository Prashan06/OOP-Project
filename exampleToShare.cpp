#include <iostream>

using namespace std;

class BankAccount {
private:
    int money;

public:
    BankAccount(int initialMoney) : money(initialMoney) {}

    // Friend function declaration
    friend class BankManager;

    // Function to display the current money
    void displayMoney() const {
        cout << "Current money: $" << money << endl;
    }
};

class BankManager {
public:
    // Function to modify the money variable of BankAccount
    void modifyMoney(BankAccount &account, int amount) {
        account.money += amount;
    }
};

int main() {
    BankAccount myAccount(100); // Create a BankAccount object with $100
    BankManager manager; // Create a BankManager object

    myAccount.displayMoney(); // Display initial money

    manager.modifyMoney(myAccount, 50); // Add $50 to the account
    myAccount.displayMoney(); // Display updated money

    manager.modifyMoney(myAccount, -30); // Subtract $30 from the account
    myAccount.displayMoney(); // Display updated money

    return 0;
}
