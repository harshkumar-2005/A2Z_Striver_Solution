#include <iostream>
#include<vector>

using namespace std;


// The solution in big O(2^n) better solution is DP
bool check(vector<int> &nums, int n, int k)
{
    if (k == 0)
        return true;
    if (k < 0)
        return false;
    if (n == 0)
        return false;

    int include = check(nums, n - 1, k - nums[n - 1]);
    int exclude = check(nums, n - 1, k);

    return include || exclude;
}
bool checkSubsequenceSum(vector<int> &nums, int k)
{
    int n = nums.size();

    int ans = check(nums, n, k);

    return ans;
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int k = 9;

    if (checkSubsequenceSum(nums, k))
        cout << "Yes, subsequence sum " << k << " exists." << endl;
    else
        cout << "No subsequence with sum " << k << " found." << endl;

    return 0;
}