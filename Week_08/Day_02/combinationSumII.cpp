#include <iostream>
#include <vector>
#include <algorithm>  // for sort

using namespace std;

void backtrack(vector<int> &candidates, int target, int index, vector<int> &curr, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(curr);
        return;
    }

    if (target < 0) return;

    for (int i = index; i < candidates.size(); i++)
    {
        // Skip duplicates at the same level
        if (i > index && candidates[i] == candidates[i - 1]) continue;

        curr.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i + 1, curr, res); // i+1 → use each element at most once
        curr.pop_back(); // undo
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end()); // sort first to handle duplicates
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(candidates, target, 0, curr, res);
    return res;
}

int main()
{
    vector<int> arr = {2, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(arr, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }

    return 0;
}
