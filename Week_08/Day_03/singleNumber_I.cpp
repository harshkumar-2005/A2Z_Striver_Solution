#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
    int res = 0;

    for(int i=0; i<nums.size(); i++)
    {
        res = res ^ nums[i];
    }
    return res;
}

int main()
{
    vector<int> arr = {1,1,2,3,2,3,4,5,6,4,5};  // 6 is the term.

    int ans = singleNumber(arr);
    cout<<ans; 

    return 0;
}