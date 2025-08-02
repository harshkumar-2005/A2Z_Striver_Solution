#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int> &nums, int target)  {
       int n = nums.size();
       int low = 0;
       int high = n - 1;

       while(low <= high)
       {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
       }

       return low;
    }

int main() {
    vector<int> nums = {1, 3, 5, 6};

    // Test cases
    int targets[] = {5, 2, 7, 0};
    
    for (int target : targets) {
        int index = searchInsert(nums, target);
        cout << "Target " << target << " would be at index: " << index << endl;
    }

    return 0;
}

// This the output
// Target 5 would be at index: 2
// Target 2 would be at index: 1
// Target 7 would be at index: 4
// Target 0 would be at index: 0