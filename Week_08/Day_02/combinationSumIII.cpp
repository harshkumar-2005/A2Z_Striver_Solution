#include <iostream>
#include <vector>
using namespace std;


    void backtrack(int start, int k, int n, vector<int>& curr, vector<vector<int>>& res) {
        // base case: found a valid combination
        if (curr.size() == k && n == 0) {
            res.push_back(curr);
            return;
        }

        // stop if invalid
        if (curr.size() > k || n < 0) return;

        // try numbers from 'start' to 9
        for (int i = start; i <= 9; i++) {
            curr.push_back(i);                 // choose
            backtrack(i + 1, k, n - i, curr, res); // recurse with reduced sum
            curr.pop_back();                   // undo (backtrack)
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(1, k, n, curr, res);
        return res;
    }

int main() {
    
    int k = 3, n = 7;
    vector<vector<int>> ans = combinationSum3(k, n);

    cout << "[ ";
    for (auto &vec : ans) {
        cout << "[ ";
        for (int num : vec) cout << num << " ";
        cout << "]";
    }
    cout << " ]" << endl;
    return 0;
}
