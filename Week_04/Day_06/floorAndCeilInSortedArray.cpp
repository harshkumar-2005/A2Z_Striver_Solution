#include <iostream>
#include <vector>

using namespace std;

vector<int> getFloorAndCeil(vector<int> nums, int x) 
{
    vector<int> res(2);

    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    res[0] = (high >= 0) ? nums[high] : -1;  // floor
    res[1] = (low < n)  ? nums[low]  : -1;   // ceil

    return res;
}

int main() 
{
    vector<int> nums = {2, 4, 6, 8, 10};  // sorted with duplicates if needed
    int x;

    cout << "Enter a number to find floor and ceil: ";
    cin >> x;

    vector<int> result = getFloorAndCeil(nums, x);

    cout << "Floor: " << result[0] << endl;
    cout << "Ceil: " << result[1] << endl;

    return 0;
}
