#include<iostream>
#include<vector>

using namespace std;

int findMissingNumber(vector<int> arr)
{
    int missing =0;

    for(int i=0; i<=arr.size(); i++)
    {
        missing ^= i; 
    }
    
    for(int i=0; i<arr.size(); i++)
    {
        missing ^= arr[i]; 
    }

    return missing;
}

int main()
{
    vector<int> arr = {0, 2, 3, 1, 4};

    int ans = findMissingNumber(arr);

    cout<<ans;

    return 0;
}