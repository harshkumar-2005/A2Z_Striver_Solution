#include <iostream>
#include <vector>

using namespace std;

// brute force Big O(n^2).

long long subArrayRangesBrute(vector<int> &nums)
{
    int n = nums.size();
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int mn = nums[i], mx = nums[i];
        for (int j = i; j < n; j++)
        {
            mn = min(mn, nums[j]);
            mx = max(mx, nums[j]);
            ans += (mx - mn);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << subArrayRangesBrute(nums) << endl;
}
