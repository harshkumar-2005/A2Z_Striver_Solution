#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int subarraysWithXorK(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int count = 0;
    int curr_xor = 0;

    for (int i = 0; i < nums.size(); i++) {
        curr_xor ^= nums[i];

        // Case 1: Subarray from 0 to i has XOR == k
        if (curr_xor == k)
            count++;

        // Case 2: Check how many times curr_xor ^ k has appeared
        if (freq.find(curr_xor ^ k) != freq.end())
            count += freq[curr_xor ^ k];

        // Update frequency of current prefix XOR
        freq[curr_xor]++;
    }

    return count;
}


int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;

    int sol = subarraysWithXorK(nums, k);

    cout<<sol;
    
    return 0;
}