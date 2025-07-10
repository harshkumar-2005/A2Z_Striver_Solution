#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    int n = nums.size();
    vector<pair<int, int>> arr; // {value, original index}
    
    for(int i = 0; i < n; i++)
        arr.push_back({nums[i], i});

    sort(arr.begin(), arr.end());

    int low = 0, high = n - 1;
    while(low < high)
    {
        int sum = arr[low].first + arr[high].first;
        if(sum == target)
        {
            return {arr[low].second, arr[high].second};
        }
        else if(sum < target)
        {
            low++;
        }
        else
        {
            high--;
        }
    }

    return {};
}

int main()
{
    vector<int> nums = {1, 6, 2, 10, 3};
    int target = 7;

    vector<int> ans = twoSum(nums, target);

    for(int x : ans)
    {
        cout<<x<<" ";
    }

    return 0;
}