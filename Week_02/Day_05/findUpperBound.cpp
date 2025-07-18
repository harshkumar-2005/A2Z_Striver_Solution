#include<iostream>
#include<vector>

using namespace std;


// The array of nums is already sorted
int upperBound(vector<int> &nums, int x)
{
    int n = nums.size();

    int low =0;
    int high = n-1;
    int ans = n;

    while(low <= high)
    {
        int mid = (high + low) / 2;

        if(nums[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,2,2,3};
    
    int ans = upperBound(nums, 2);

    cout<<ans;

    return 0;
}