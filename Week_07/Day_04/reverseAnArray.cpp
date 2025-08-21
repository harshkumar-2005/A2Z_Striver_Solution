#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> &arr, int start, int end) {
    if (start >= end)
        return;

    swap(arr[start], arr[end]);
    helper(arr, start + 1, end - 1);
}

void reverse(vector<int> &arr) {
    helper(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    reverse(arr);

    cout << "Reversed array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
