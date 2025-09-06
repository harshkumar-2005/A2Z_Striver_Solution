#include <iostream>
#include <algorithm>

using namespace std;

int trapRainWater(int arr[], int n) {
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int res = 0;

    while (left <= right) {
        if (arr[left] <= arr[right]) {
            if (arr[left] >= leftMax)
                leftMax = arr[left];
            else
                res += (leftMax - arr[left]);
            left++;
        } else {
            if (arr[right] >= rightMax)
                rightMax = arr[right];
            else
                res += (rightMax - arr[right]);
            right--;
        }
    }
    return res;
}

int main() {
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Total trapped rain water: " << trapRainWater(arr, n) << endl;

    return 0;
}
