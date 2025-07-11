#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums) 
{
    vector<int> pos;
    vector<int> neg;
    
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] > 0) //we assume array will not have zero
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }

    int i = 1;
    int j = 0;

    nums[0] = pos[0];
    for(int x=1; x<nums.size(); x++)
    {

        if(x%2 == 0)
        {
            nums[x] = pos[i++];
        }
        else
        {
            nums[x] = neg[j++];
        }
    }

    return nums;
}

int main()
{
    vector<int> nums = {2, 4, 5, -1, -3, -4};

    vector<int> res = rearrangeArray(nums);

    for(int x : res)
    {
        cout<<x<<" ";
    }

    return 0;
}