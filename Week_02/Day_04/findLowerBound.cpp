// The array will be unordered 
// Time :- O(n log n)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int binarySearch(vector<int> &arr, int target)
{
    int low =0;
    int high = arr.size() - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return 0;
}

int findLowerBound(vector<int> &arr, int x)
{
    sort(arr.begin(), arr.end());

    int found = -1;

    // Binary search 
    found = binarySearch(arr, x-1);

    if(found != 0)
    {
        return arr[found - 1];
    }


    return x;

}

int main()
{
    vector<int> arr= {3,5,8,15,19};
    int x = 9;

    int ans = findLowerBound(arr,x);

    cout<<ans;

    return 0;

}