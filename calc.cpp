#include <iostream>
using namespace std;

int main() {
    
    string operation;
    double num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter Operation (+, -, *, /): ";
    cin >> operation;
    cout << "Enter the second number: ";
    cin >> num2;

    if (operation == "+") {
        cout << num1 + num2;

    } else if (operation == "-") {
        cout << num1 - num2;

    } else if (operation == "*") {
        cout << num1 * num2;

    } else if (operation == "/") {
        cout << num1 / num2;
    } else {
        cout << "Unrecognized operation";
    }
    return 0;

}