#include<iostream>
#include<vector>

using namespace std;

string removeOuterParentheses(string s) 
{
    string result;
    int depth = 0;

    for (char ch : s) {
        if (ch == '(') {
            if (depth > 0) {
                result += ch;
            }
            depth++;
        } else if (ch == ')') {
            depth--;
            if (depth > 0) {
                result += ch;
            }
        }
    }

    return result;
}

int main() {
    string input = "(()())(())(()(()))";
    string output = removeOuterParentheses(input);
    cout << "Result: " << output << endl;
    return 0;
}
