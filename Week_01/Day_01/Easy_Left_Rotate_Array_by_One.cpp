#include<iostream>
#include<vector>

using namespace std;

vector<int> leftRotateByOne(vector<int>& nums)
{

    int ele = nums[0];

    for(int i=1; i<nums.size(); i++)
    {
        nums[i-1] = nums[i];
    }

    nums[nums.size()-1] = ele;

    return nums;
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,12};

    vector<int> res = leftRotateByOne(nums);


    for(int x : res)
    {
        cout<<x<<" ";
    }

    return 0;
}