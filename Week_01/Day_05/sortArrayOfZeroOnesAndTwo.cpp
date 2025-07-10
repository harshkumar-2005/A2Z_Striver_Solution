#include<iostream>
#include<vector>

using namespace std;

void DutchNationalFlagAlgo(vector<int>& nums) 
{
    int n = nums.size();
    int low = 0, mid = 0;
    int high = n-1;

    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[mid] , nums[low]);
            low++;  mid++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid],nums[high]);
            high--;
        }
    }
    
}

int main()
{

    vector<int> nums = {0,1,1,0,0,2,0,1,0,2,0,2};

    DutchNationalFlagAlgo(nums);

    for(int x : nums)
    {
        cout<<x<<" ";
    }

    // output:- 0 0 0 0 0 0 1 1 1 2 2 2 

    return 0;
}