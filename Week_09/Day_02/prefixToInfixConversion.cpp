#include<iostream>
#include<stack>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToInfix(string s) {
    stack<string> st;

    // Traverse from right to left
    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];

        // If operand, push to stack
        if (!isOperator(c)) {
            string op(1, c); // convert char to string
            st.push(op);
        }
        // If operator, pop two operands and combine
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }

    // Final expression on stack
    return st.top();
}

int main() {
    string exp1 = "+ab";
    string exp2 = "*+ab-cd";

    cout << prefixToInfix(exp1) << endl; // (a+b)
    cout << prefixToInfix(exp2) << endl; // ((a+b)*(c-d))

    return 0;
}