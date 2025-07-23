#include<iostream>
#include<vector>

using namespace std;

// use finding minimum in the array using binary search logic and just retun index of that instead of element.
int findKRotation(vector<int> &nums)  
{
    int n = nums.size();
    
    int low = 0;
    int high = n-1;

    while(low < high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;

}

int main()
{
    vector<int> v = {4, 5, 6, 7, 0, 1, 2, 3};

    int ans = findKRotation(v);

    cout<<ans;

    return 0;
}