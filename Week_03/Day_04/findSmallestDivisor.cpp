#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper function to compute the sum of ceil(nums[i]/divisor)
    int computeSum(const vector<int>& nums, int divisor) {
        int total = 0;
        for (int num : nums) {
            total += (num + divisor - 1) / divisor;  // ceil(num / divisor)
        }
        return total;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int currentSum = computeSum(nums, mid);

            if (currentSum <= threshold) {
                answer = mid;        // possible answer
                high = mid - 1;      // try to find smaller divisor
            } else {
                low = mid + 1;       // need a bigger divisor
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    Solution sol;
    int result = sol.smallestDivisor(nums, threshold);
    cout << "Smallest divisor is: " << result << endl;

    return 0;
}
