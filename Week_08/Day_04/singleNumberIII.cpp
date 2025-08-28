#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int xorAll = 0;
    for (int n : nums) xorAll ^= n;

    // get rightmost set bit
    int diff = xorAll & (-xorAll);

    int a = 0, b = 0;
    for (int n : nums) {
        if (n & diff) a ^= n; // group 1
        else b ^= n;          // group 2
    }

    return {a, b};
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 5};

    vector<int> result = singleNumber(nums);

    cout << "The two unique numbers are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
