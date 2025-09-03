#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert Prefix expression to Postfix
string prefixToPostfix(string prefix) {
    stack<string> st;

    // Traverse from right to left
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];

        // If operand, push it as string
        if (!isOperator(c)) {
            st.push(string(1, c));
        }
        // If operator, pop two operands and combine
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Postfix = operand1 + operand2 + operator
            string newExpr = op1 + op2 + c;

            // Push the result back to stack
            st.push(newExpr);
        }
    }

    return st.top();
}

int main() {
    string prefix = "*+AB-CD"; 

    cout << "Prefix Expression : " << prefix << endl;
    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;

    return 0;
}
