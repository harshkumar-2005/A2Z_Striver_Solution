#include<iostream>
#include<deque>
#include<vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // will store indices
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // 1. Remove indices that are out of the current window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // 2. Remove elements smaller than current from the back
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {    
            dq.pop_back();
        }

        // 3. Add current index
        dq.push_back(i);

        // 4. Record the maximum for current window
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(arr, k);

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
