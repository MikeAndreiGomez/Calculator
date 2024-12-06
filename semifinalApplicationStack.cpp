#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

vector <string> infinixToPostfix(const string &expression) {
    stack<char> operators;
    vector<string> output;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            output.push_back(token);
        } else if (token[0] == '(') {
            operators.push('(');
        } else if (token[0] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token[0])) {
                output.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.push(token[0]);
        }
    }

    while (!operators.empty()) {
        output.push_back(string(1, operators.top()));
        operators.pop();
    }

    return output;
}

int evaluatePostfix(const vector<string> &postfix) {
    stack<int> numbers;

    for (const string &token : postfix) {
        if (isdigit(token[0])) {
            numbers.push(stoi(token));
        } else {
            int b = numbers.top(); numbers.pop();
            int a = numbers.top(); numbers.pop();
            if (token[0] == '+') numbers.push(a + b);
            else if (token[0] == '-') numbers.push(a - b);
            else if (token[0] == '*') numbers.push(a * b);
            else if (token[0] == '/') numbers.push(a / b);
        }
    }

    return numbers.top();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    vector<string> postfix = infinixToPostfix(expression);
    int result = evaluatePostfix(postfix);

    cout << "Result: " << result << endl;
    return 0;
}