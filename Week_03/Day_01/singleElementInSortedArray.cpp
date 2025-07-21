#include<iostream>
#include<vector>

using namespace std;

int singleNonDuplicate(vector<int> &nums) 
{
    int n = 0;

    for(int i = 0; i<nums.size(); i++)
    {
        n ^= nums[i];
    }

    return n;
}


int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    int ans = singleNonDuplicate(nums);

    cout<<ans;

    return 0;
}

// output :- 4