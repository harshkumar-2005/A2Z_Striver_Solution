// Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. The output can be returned in any order.

#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> majorityElementTwo(vector<int>& nums) {

    vector<int> res;
    map<int, int> mp;
    
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    int check = nums.size()/3;
    for(auto it= mp.begin(); it!=mp.end(); it++)
    {
        if(it->second > check)
        {
            res.push_back(it->first);
        }
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 2, 1, 1, 3, 2, 2};

    vector<int> ans = majorityElementTwo(nums);

    for(int x : ans)
    {
        cout<<x<<" ";
    }
    return 0;
}