#include <iostream>
#include <vector>
using namespace std;

int findCelebrity(vector<vector<int>>& M) {
    int n = M.size();
    int candidate = 0;
    
    // Step 1: Find the candidate
    for (int i = 1; i < n; i++) {
        if (M[candidate][i] == 1) {
            candidate = i;
        }
    }
    
    // Step 2: Verify the candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (M[candidate][i] == 1 || M[i][candidate] == 0) {
                return -1;
            }
        }
    }
    
    return candidate;
}

int main() {
    vector<vector<int>> M1 = {{0,1,1,0}, {0,0,0,0}, {1,1,0,0}, {0,1,1,0}};
    cout << findCelebrity(M1) << endl;  // Output: 1

    vector<vector<int>> M2 = {{0,1}, {1,0}};
    cout << findCelebrity(M2) << endl;  // Output: -1

    return 0;
}