#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k) {

    vector<int> ans = a; // Start with a copy of a
    ans.insert(ans.end(), b.begin(), b.end()); // Append b to ans
    sort(ans.begin(), ans.end());
    
    return ans[k - 1];
    }

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    int sol = kthElement(a, b, k);
    cout<<sol;

    return 0;
}