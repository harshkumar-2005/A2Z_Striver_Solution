#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool canSplit(vector<int> &a, int k, int limit)
{
    int cnt = 1;
    int currmax = 0;

    for (int x : a)
    {
        if (currmax + x > limit)
        {
            cnt++;
            currmax = x;
            if (cnt > k)
                return false;
        }
        else
        {
            currmax += x;
        }
    }

    return true;
}

int largestSubarraySumMinimized(vector<int> &a, int k)
{
    // The idea to solve this problem is range from the largest value in the array to sum of all element 

    long long low = *max_element(a.begin(), a.end());
    long long high = accumulate(a.begin(), a.end(), 0LL);
    long long ans = high;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (canSplit(a, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return (int)ans;
}

int main()
{
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << "Minimized Largest Sum: " << largestSubarraySumMinimized(nums, k) << endl;

    return 0;
}
