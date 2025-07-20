#include<iostream>
#include<vector>

using namespace std;

int findPeakElement(vector<int> &arr) 
{
    int n = arr.size();

    if(n == 1)      return 0;
     
    if(arr[0] > arr[1])     return 0; // First element is the peak

    if(arr[n-1] > arr[n-2])     return n-1; // Last element is the peak

    //binary search for peak use from index 1 to n-2

    int low = 1;
    int high = n-2;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }


        if(arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};

    int ans = findPeakElement(arr);

    cout<<ans;

    return 0;
}