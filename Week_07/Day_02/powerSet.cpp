#include<iostream>
#include<vector>

using namespace std;

void helper(int index, vector<vector<int>> &res, vector<int> &current, vector<int> &nums)
{
    if(index == nums.size())
    {
        res.push_back(current);
        return;
    }

    // excluding the index
    helper(index+1, res, current, nums);

    // include the index
    current.push_back(nums[index]);
    helper(index+1, res, current, nums);

    current.pop_back();
}

vector<vector<int> > powerSet(vector<int>& nums) 
{
    vector<vector<int>> res;
    vector<int> current;
    helper(0, res, current, nums);

    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = powerSet(nums);

    cout << "[ ";
    for (auto &subset : ans) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << "]" << endl;

    return 0;
}