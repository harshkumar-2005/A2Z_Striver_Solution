#include<iostream>
#include<vector>

using namespace std;

int countSubseq(vector<int>& nums, int n, int sum)
{
    // Base cases
    if (sum == 0) return 1;          // found a valid subsequence
    if (n == 0) return 0;            // no elements left
    if (sum < 0) return 0;           // sum exceeded (if all nums >= 0)

    // Choices: exclude or include nums[n-1]
    int exclude = countSubseq(nums, n-1, sum);
    int include = countSubseq(nums, n-1, sum - nums[n-1]);

    int res = exclude + include;

    return res; 

}

int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    int n = nums.size();

    int ans = countSubseq(nums, n, k);

    return ans;
}

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    int ans = countSubsequenceWithTargetSum(nums, target);

    cout << "Number of subsequences with sum " << target << " = " << ans << endl;

    return 0;
}