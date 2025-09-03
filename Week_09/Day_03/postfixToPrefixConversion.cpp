#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert Postfix to Prefix
string postfixToPrefix(string postfix) {
    stack<string> st;

    // Traverse from left to right
    for (int i = 0; i < postfix.size(); i++) {
        char c = postfix[i];

        // If operand, push to stack
        if (!isOperator(c)) {
            st.push(string(1, c));
        }
        // If operator, pop two operands and combine
        else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            // Prefix = operator + operand1 + operand2
            string newExpr = c + op1 + op2;

            // Push back to stack
            st.push(newExpr);
        }
    }

    return st.top();
}

int main() {
    string postfix = "AB+CD-*"; 

    cout << "Postfix Expression : " << postfix << endl;
    cout << "Prefix Expression  : " << postfixToPrefix(postfix) << endl;

    return 0;
}
