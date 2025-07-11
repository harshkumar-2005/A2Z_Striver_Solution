#include<iostream>
#include<vector>

using namespace std;

int maxSubArray(vector<int>& nums) 
{
        int finalsum = INT_MIN;
        int currsum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currsum += nums[i];

            finalsum = max(finalsum, currsum);

            if (currsum < 0) {
                currsum = 0;
            }
        }

        return finalsum;
}

int main()
{
    vector<int> nums = {-2, -3, -7, -2, -10, -4};

    int res;
    res = maxSubArray(nums);
    cout<<res;  // Output :- -2 

    return 0;
}
