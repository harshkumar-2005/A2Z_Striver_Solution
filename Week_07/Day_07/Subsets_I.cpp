#include <iostream>
#include <vector>

using namespace std;

void helper(int index, int currsum, vector<int> &nums, vector<int> &res)
{
    if (index == nums.size())
    {
        res.push_back(currsum);
        return;
    }

    // Exclude nums[index]
    helper(index + 1, currsum, nums, res);

    // Include nums[index]
    helper(index + 1, currsum + nums[index], nums, res);
}

vector<int> subsetSums(vector<int> &nums)
{
    vector<int> res;
    helper(0, 0, nums, res);

    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<int> result = subsetSums(nums);

    cout << "Subset sums are: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}