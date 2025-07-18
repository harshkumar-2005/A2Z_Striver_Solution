// The array will be unordered 
// Time :- O(n log n)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// The array arr is already sorted
int findLowerBound(vector<int> &arr, int x)
{
   int n = arr.size();
   
   int low = 0;
   int high = n-1;
   int ans = n;

   while(low <= high)
   {
    int mid = (low + high) / 2;

    if(arr[mid] >= x)
    {
        ans = mid;
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }
   }

   return ans;
}

int main()
{
    vector<int> arr= {3,5,8,15,19};
    int x = 9;

    int ans = findLowerBound(arr,x);

    cout<<ans;

    return 0;

}