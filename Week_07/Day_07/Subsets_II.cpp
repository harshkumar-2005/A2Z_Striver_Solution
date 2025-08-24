#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(int index, vector<int> &nums, vector<int> &current, vector<vector<int>> &result)
{
    // Add the current subset
    result.push_back(current);

    // Explore further elements
    for (int i = index; i < nums.size(); i++)
    {
        // Skip duplicates at the same recursion level
        if (i > index && nums[i] == nums[i - 1])
            continue;

        current.push_back(nums[i]);
        backtrack(i + 1, nums, current, result);
        current.pop_back(); // backtrack
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // sort so duplicates are adjacent
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, nums, current, result);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> ans = subsetsWithDup(nums);

    cout << "Unique subsets:" << endl;
    for (auto &subset : ans)
    {
        cout << "[ ";
        for (int x : subset)
            cout << x << " ";
        cout << "]" << endl;
    }

    return 0;
}
