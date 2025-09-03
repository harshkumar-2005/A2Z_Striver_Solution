#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// Function to check precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert Infix to Postfix (helper)
string infixToPostfix(string infix) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If operand, add to result
        if (isalnum(c)) {
            result += c;
        }
        // If '(', push to stack
        else if (c == '(') {
            st.push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Remove '('
        }
        // If operator
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                if (c == '^' && st.top() == '^') break; // Right associativity
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

// Function to convert Infix to Prefix
string infixToPrefix(string infix) {
    // Step 1: Reverse the infix string
    reverse(infix.begin(), infix.end());

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Step 3: Get postfix of the modified expression
    string postfix = infixToPostfix(infix);

    // Step 4: Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string infix = "((A+B)*(C-D))"; 

    cout << "Infix Expression  : " << infix << endl;
    cout << "Prefix Expression : " << infixToPrefix(infix) << endl;

    return 0;
}
