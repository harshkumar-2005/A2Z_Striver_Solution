#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool canWePlace(vector<int> &nums, int dist, int cows)
{
    int cntcow = 1, last = nums[0];
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] - last >= dist)
        {
            cntcow++;   last = nums[i];
        }
        if(cntcow >= cows)      return true;
    }

    return false;
}

int aggressiveCows(vector<int> &nums, int k) 
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int low = 1, high = nums[n-1] - nums[0];
    
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(canWePlace(nums, mid, k))
        {
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return high;
}

int main()
{
    vector<int> nums = {0, 3, 4, 7, 10, 9};
    int n = 6, k = 4;
    int ans = aggressiveCows(nums, k);

    cout<<ans;

    return 0;
}