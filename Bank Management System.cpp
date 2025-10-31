#include <iostream>
#include <vector>
using namespace std;

class Account {
    int accNo;
    string name;
    double balance;
public:
    Account(int a, string n, double b): accNo(a), name(n), balance(b) {}
    void deposit(double amt) { balance += amt; }
    void withdraw(double amt) { if (amt <= balance) balance -= amt; else cout << "Insufficient funds!\n"; }
    void display() const { cout << accNo << " " << name << " " << balance << "\n"; }
    int getAccNo() const { return accNo; }
};

int main() {
    vector<Account> accounts;
    int ch;
    do {
        cout << "\n1. Add Account\n2. Deposit\n3. Withdraw\n4. Display All\n5. Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) {
            int a; string n; double b;
            cout << "Enter AccNo, Name, Balance: ";
            cin >> a >> n >> b;
            accounts.emplace_back(a, n, b);
        } else if (ch == 2) {
            int a; double amt;
            cout << "Enter AccNo and amount: ";
            cin >> a >> amt;
            for (auto &acc : accounts)
                if (acc.getAccNo() == a) acc.deposit(amt);
        } else if (ch == 3) {
            int a; double amt;
            cout << "Enter AccNo and amount: ";
            cin >> a >> amt;
            for (auto &acc : accounts)
                if (acc.getAccNo() == a) acc.withdraw(amt);
        } else if (ch == 4) {
            for (auto &acc : accounts) acc.display();
        }
    } while (ch != 5);
}
