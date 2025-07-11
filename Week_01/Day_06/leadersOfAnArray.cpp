#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> leaders(vector<int>& nums)
{
    //Last element is always a leader
    vector<int> res;
    
    res.push_back(nums[nums.size()-1]);
    int check = nums[nums.size()-1];
    for(int i= nums.size()-2; i>= 0; i--)
    {
        if(nums[i] > check)
        {
            check = nums[i];
            res.push_back(nums[i]);
        }
    }

    reverse(res.begin(), res.end());    
    return res;
}

int main()
{

    vector<int> nums = {-3, 4, 5, 1, -4, -5};
    vector<int> res = leaders(nums);

    for(int i : res)
    {
        cout<<i<<" ";
    }

    // Expected Output 5 1 -4 -5

    return 0;
}