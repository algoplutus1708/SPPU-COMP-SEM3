#include <iostream>
#include <stack>

using namespace std;

string postfixToInfix(const string& postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            string operand2 = s.top();
            s.pop();

            string operand1 = s.top();
            s.pop();

            string result = "(" + operand1 + c + operand2 + ")";
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    // Example postfix expression: AB+C*
    string postfixExpression;
    cout << "Enter the postfix expression: ";
    cin >> postfixExpression;

    string infixExpression = postfixToInfix(postfixExpression);

    cout << "Infix Expression: " << infixExpression << endl;

}
