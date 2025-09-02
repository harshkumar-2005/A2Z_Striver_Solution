#include <iostream>
#include <stack>
#include <string>
using namespace std;

// helper function to define precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// function to convert infix to postfix
string infixToPostfix(string& s) {
    stack<char> st;
    string res;

    for (char c : s) {
        // If operand, add to result
        if (isalnum(c)) {
            res += c;
        }
        // If '(', push
        else if (c == '(') {
            st.push(c);
        }
        // If ')', pop till '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // pop '('
        }
        // If operator
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop remaining operators
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

int main() {
    string infix = "(A+B)*C-(D/E^F)*G";
    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
