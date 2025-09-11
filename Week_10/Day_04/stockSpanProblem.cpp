#include <iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> calculateSpan(vector<int>& arr, int n) {
    vector<int> span(n);
    stack<int> st;  // will store indices

    for (int i = 0; i < n; i++) {
        // Pop elements from stack while current price is greater
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        // If stack is empty, all previous elements are smaller
        span[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // Push this element’s index onto stack
        st.push(i);
    }

    return span;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = calculateSpan(arr, n);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
