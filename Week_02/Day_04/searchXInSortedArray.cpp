#include<iostream>
#include<vector>

using namespace std;

bool binarySearch(vector<int> &arr, int target)
{
    int low =0;
    int high = arr.size() - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target)
        {
            return true;
        }
        else if(arr[mid] > target)
        {
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return false;
}

int main()
{
    vector<int> arr = {1,2,3,4,6,7,8,12,13,14,15};
    int target = 21;

    if(binarySearch(arr, target))
    {
        cout<<"The element is present in the array";
    }
    else
    {
        cout<<"The element is not present int the array";
    }

    return 0;
}