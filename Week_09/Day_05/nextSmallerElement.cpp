#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmallerElements(const vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);  // default = -1
    stack<int> st;           // will store elements (not indexes)

    // traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // pop bigger or equal elements
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        // if stack not empty, top is the next smaller
        if (!st.empty()) {
            res[i] = st.top();
        }
        // push current element
        st.push(arr[i]);
    }

    return res;
}


int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> ans = nextSmallerElements(arr);

    cout << "Next smaller elements: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}