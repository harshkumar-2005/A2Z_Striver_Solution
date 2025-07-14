#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int maxLen(vector<int>& arr) 
{
    unordered_map<int, int> mp;
    int prefixSum = 0, maxLen = 0;

    mp[0] = -1;

    for (int i = 0; i < arr.size(); i++) 
    {
        prefixSum += arr[i];

        if (mp.find(prefixSum) != mp.end()) 
        {
            maxLen = max(maxLen, i - mp[prefixSum]);
        } 
        else 
        {
            mp[prefixSum] = i;
        }
    }

    return maxLen;
}


int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    int res = maxLen(arr);
    cout<<res;

    return 0;
}

// output :- 5