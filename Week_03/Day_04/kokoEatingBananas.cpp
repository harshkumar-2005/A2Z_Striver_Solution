#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canEatAll(piles, h, mid)) {
                ans = mid;
                right = mid - 1; // Try smaller speed
            } else {
                left = mid + 1; // Need faster speed
            }
        }

        return ans;
    }

private:
    bool canEatAll(const vector<int>& piles, int h, int k) {
        int totalHours = 0;
        for (int pile : piles) {
            totalHours += (pile + k - 1) / k; // ceil(pile / k)
        }
        return totalHours <= h;
    }
};

int main() {
    // Example input
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    Solution sol;
    int result = sol.minEatingSpeed(piles, h);

    cout << "Minimum eating speed Koko needs: " << result << endl;

    return 0;
}
