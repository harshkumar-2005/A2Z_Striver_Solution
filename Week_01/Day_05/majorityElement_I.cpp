#include<iostream>
#include<vector>

using namespace std;

int majorityEle(vector<int> nums)
{
    int n = nums.size();
    int count =0;
    int ele;

    for(int i=0; i<n; i++)
    {
        if(count == 0)
        {
            ele = nums[i];
            count = 1;
        }
        else if(ele == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }


    }

    int cnt1 =0;
    for(int i=0; i<n; i++)
    {
        if(nums[i] == ele)
        {
            cnt1++;
        }
    }
    if(cnt1 > n/2)  return ele;


    return -1;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int res = majorityEle(nums);

    cout<<res;
    // output:- 2
    return 0;
}