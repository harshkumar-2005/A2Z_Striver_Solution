#include<iostream>
#include<vector>

using namespace std;

int findMin(vector<int> &arr)
{
    int ans = INT_MAX;

    int low = 0;
    int high = arr.size()-1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[low] < arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};

    int min = findMin(arr);

    cout<<min;

    return 0;
}

// Alternate method:-

/*
int findMin(vector<int> &arr)  
{
      int n = INT_MAX;
      int low = 0;
      int high = arr.size()-1;

      while(low < high)
      {
        int mid = low + (high - low) / 2;
        if(arr[mid] > arr[high])
        {
          low = mid + 1;
        }
        else
        {
          high = mid;
        }
      }

      return arr[low];
}

*/