#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<int> findMissingAndRepeating(vector<int>& nums) {
    unordered_set<int> seen;
    int n = nums.size();
    int repeat = -1, total_sum = 0;

    for (int i = 0; i < n; i++) {
        if (seen.count(nums[i])) {
            repeat = nums[i]; // Found the repeating number
        } else {
            seen.insert(nums[i]);
            total_sum += nums[i]; // Accumulate unique values
        }
    }

    int expected_sum = n * (n + 1) / 2;
    int missing = expected_sum - total_sum;

    return {repeat, missing};
}


int main()
{
    vector<int> nums = {3, 5, 4, 1, 1};

    vector<int> ans = findMissingAndRepeating(nums);
    
    for(int x : ans)
    {
        cout<<x<<" ";
    }

    return 0;
}