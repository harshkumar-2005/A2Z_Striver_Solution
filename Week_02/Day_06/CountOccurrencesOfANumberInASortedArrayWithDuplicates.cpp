#include<iostream>
#include<vector>

using namespace std;

int searchRange(vector<int> &nums, int target) 
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

    return (last - first+1);
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    int ans = searchRange(nums, target);

    cout<<ans;

    return 0;
}