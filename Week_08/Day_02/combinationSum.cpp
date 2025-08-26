#include<iostream>
#include<vector>

using namespace std;

void backtrack(vector<int>& candidates, int target, int index, vector<vector<int>>& res, vector<int>& curr) 
{
    if (target == 0) {
        res.push_back(curr);
        return;
    }

    // Stop if target < 0 or we exhausted array
    if (target < 0 || index == candidates.size()) return;

    // Choice 1: Pick the current element
    curr.push_back(candidates[index]);
    backtrack(candidates, target - candidates[index], index, res, curr); // can reuse same index
    curr.pop_back(); // undo choice

    // Choice 2: Skip the current element and move forward
    backtrack(candidates, target, index + 1, res, curr);
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> curr;
    vector<vector<int>> res;
    backtrack(candidates, target, 0, res, curr);

    return res;
}

int main() {
    vector<int> candidates = {1, 2, 3, 6, 7};  // Example input
    int target = 7;

    vector<vector<int>> res;
    vector<int> curr;

    backtrack(candidates, target, 0, res, curr);

    cout << "Combinations that sum to " << target << ":\n";
    for (auto& comb : res) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}