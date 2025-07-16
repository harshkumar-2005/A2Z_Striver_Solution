#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    vector<int> v;

    int i=0;
    int j=0;

    while(i<m && j<n)
    {
        if(nums1[i] <= nums2[j])
        {
            v.push_back(nums1[i]);
            i++;
        }
        else
        {
            v.push_back(nums2[j]);
            j++;
        }
    }

    while(i<m)
    {
        v.push_back(nums1[i]);
        i++;
    }

    while(j<n)
    {
        v.push_back(nums2[j]);
        j++;
    }

    nums1.clear();

    nums1 = v;
}

int main()
{
    vector<int>  nums1 = {-5, -2, 4, 5};
    vector<int> nums2 = {-3, 1, 8};

    merge(nums1, nums1.size(), nums2, nums2.size());

    for(int x : nums1)
    {
        cout<<x<<" ";
    }

    return 0;
}


// Output:-
// -5 -3 -2 1 4 5 8 