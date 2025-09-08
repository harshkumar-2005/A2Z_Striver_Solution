#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;

    for (char digit : num) {
        // pop from stack while last digit > current and k > 0
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }

    // if still have k left, remove from end
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    // build result from stack
    string result = "";
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());

    // remove leading zeros
    int i = 0;
    while (i < result.size() && result[i] == '0') {
        i++;
    }
    result = result.substr(i);

    return result.empty() ? "0" : result;
}

int main() {
    cout << removeKdigits("1432219", 3) << endl; // "1219"
    cout << removeKdigits("10200", 1) << endl;   // "200"
    cout << removeKdigits("10", 2) << endl;      // "0"
    return 0;
}
