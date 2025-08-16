#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(vector<string> &result, string current, int open, int close, int n) {
    if(current.size() == 2*n) {
        result.push_back(current);
        return;
    }

    // Add '(' if we still have some left
    if(open < n) {
        backtrack(result, current + "(", open + 1, close, n);
    }

    // Add ')' if valid (i.e., we have more opens than closes)
    if(close < open) {
        backtrack(result, current + ")", open, close + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(result, "", 0, 0, n);
    return result;
}

int main() {
    int n = 3;
    vector<string> ans = generateParenthesis(n);

    cout << "[ ";
    for(string &s : ans) {
        cout << "\"" << s << "\" ";
    }
    cout << "]" << endl;

    return 0;
}