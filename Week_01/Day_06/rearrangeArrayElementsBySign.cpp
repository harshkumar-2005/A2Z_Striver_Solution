#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums) 
{
    int n = nums.size();

    
    vector<int> ans(n,0);

    int posindx = 0;
    int negindx = 1;

    for(int i=0; i<n; i++)
    {
        if(nums[i] > 0)
        {
            ans[posindx] = nums[i];
            posindx += 2; 
        }
        else
        {
            ans[negindx] = nums[i];
            negindx += 2;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 4, 5, -1, -3, -4};

    vector<int> res = rearrangeArray(nums);

    for(int x : res)
    {
        cout<<x<<" ";
    }

    // output:- 2 -1 4 -3 5 -4 

    return 0;
}