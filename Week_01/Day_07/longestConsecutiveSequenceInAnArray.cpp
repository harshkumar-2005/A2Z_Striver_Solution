#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) 
{
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;

    for (int num : s) {
        // Only start a sequence if num - 1 is not in the set
        if (s.find(num - 1) == s.end()) {
            int curr = num;
            int streak = 1;

            while (s.find(curr + 1) != s.end()) {
                curr++;
                streak++;
            }

            longest = max(longest, streak);
        }
    }

    return longest;
}


int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

    int res = longestConsecutive(nums);

    cout<<res;

    //Output:- 9

    return 0;
}