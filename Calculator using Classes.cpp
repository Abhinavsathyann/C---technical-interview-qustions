#include <iostream>
using namespace std;

class Calculator {
public:
    double add(double a, double b) { return a + b; }
    double sub(double a, double b) { return a - b; }
    double mul(double a, double b) { return a * b; }
    double divi(double a, double b) {
        if (b == 0) throw runtime_error("Division by zero!");
        return a / b;
    }
};

int main() {
    Calculator c;
    double a, b; char op;
    cout << "Enter expression (a + b): ";
    cin >> a >> op >> b;
    try {
        switch (op) {
            case '+': cout << "Result: " << c.add(a, b); break;
            case '-': cout << "Result: " << c.sub(a, b); break;
            case '*': cout << "Result: " << c.mul(a, b); break;
            case '/': cout << "Result: " << c.divi(a, b); break;
            default: cout << "Invalid operator!";
        }
    } catch (exception &e) {
        cout << e.what();
    }
}
