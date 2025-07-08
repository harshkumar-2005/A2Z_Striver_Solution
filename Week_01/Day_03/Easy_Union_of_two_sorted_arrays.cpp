#include<iostream>
#include<vector>


using namespace std;

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) 
{
    int n = nums1.size();
    int m = nums2.size();
    int i = 0, j = 0;
    vector<int> res;

    while(i<n && j<m)
    {
        int val;

        if(nums1[i] == nums2[j])
        {
            val = nums1[i];
            i++;    j++;
        }
        else if(nums1[i] < nums2[j])
        {
            val = nums1[i];
            i++;
        }
        else
        {
            val = nums2[j];
            j++;
        }

        if(res.empty() || res.back() != val)
        {
            res.push_back(val);
        }
    }

    // Add remaining elements from nums1
    while(i < n)
    {
        if(res.empty() || res.back() != nums1[i])
            res.push_back(nums1[i]);
        i++;
    }

    // Add remaining elements from nums2
    while(j < m)
    {
        if(res.empty() || res.back() != nums2[j])
            res.push_back(nums2[j]);
        j++;
    }

    return res;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 7};

    vector ans = unionArray(nums1, nums2);
    
    for(int x : ans)
    {
        cout<<x<<" ";
    }
    return 0;
}