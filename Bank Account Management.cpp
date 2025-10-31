#include <iostream>
using namespace std;

class Bank {
    string name;
    int accNo;
    double balance;
public:
    void openAccount(string n, int a) {
        name = n; accNo = a; balance = 0;
        cout << "Account created successfully!\n";
    }

    void deposit(double amt) {
        balance += amt;
        cout << "Deposited: " << amt << "\nBalance: " << balance << endl;
    }

    void withdraw(double amt) {
        if (amt > balance) cout << "Insufficient balance!\n";
        else { balance -= amt; cout << "Withdrawn: " << amt << "\nBalance: " << balance << endl; }
    }

    void show() {
        cout << "\nAccount Holder: " << name << "\nAccount No: " << accNo << "\nBalance: " << balance << endl;
    }
};

int main() {
    Bank b;
    int ch; string name; int acc;
    cout << "Enter Name & Account No: "; cin >> name >> acc;
    b.openAccount(name, acc);
    do {
        cout << "\n1.Deposit 2.Withdraw 3.Show 4.Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) { double amt; cout << "Amount: "; cin >> amt; b.deposit(amt); }
        else if (ch == 2) { double amt; cout << "Amount: "; cin >> amt; b.withdraw(amt); }
        else if (ch == 3) b.show();
    } while (ch != 4);
}
