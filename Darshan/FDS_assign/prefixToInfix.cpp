#include <iostream>
#include <stack>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert prefix expression to infix expression
string prefixToInfix(const string& prefix) {
    stack<string> s;

    // Traverse the prefix expression in reverse order
    for (int i = prefix.size() - 1; i >= 0; --i) {
        char ch = prefix[i];

        if (isOperator(ch)) {
            // If operator, pop two s, concatenate them with the operator, and push the result back
            string operand1 = s.top();
            s.pop();

            string operand2 = s.top();
            s.pop();

            string result = "(" + operand1 + ch + operand2 + ")";
            s.push(result);
        } else {
            // If operand, push it onto the stack
            string str="";
            str+=ch;
            s.push(str);
        }
    }

    return s.top();
}

int main() {
    // Example prefix expression: * + A B - C D
    string prefixExpression;
    cout << "Enter the prefix expression: ";
    getline(cin, prefixExpression);

    string infixExpression = prefixToInfix(prefixExpression);

    cout << "Infix Expression: " << infixExpression << endl;

    return 0;
}
