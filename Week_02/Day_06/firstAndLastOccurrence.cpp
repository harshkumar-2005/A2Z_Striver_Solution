#include<iostream>
#include<vector>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target) 
{

    vector<int> res(2,-1);

    int first = -1;
    int last = -1;
    int low = 0;
    int high = nums.size()-1;
    
    // first occurence
    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if(nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    

    low = 0;
    high = nums.size()-1;
    
    // last occurence
    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if(nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    res[0] = first;
    res[1] = last;

    return res;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> ans = searchRange(nums, target);

    cout<<ans[0]<<" "<<ans[1];

    return 0;
}