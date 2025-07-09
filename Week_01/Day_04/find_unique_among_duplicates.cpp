#include<iostream>
#include<vector>

using namespace std;

int findUnique(vector<int>& arr)
{
    int res = arr[0];

    for(int i=1; i<arr.size(); i++)
    {
        res ^= arr[i];
    }

    return res;
}

int main()
{

    vector<int> arr = {1,2,2,1,5,6,7,8,6,5,7};

    int ans = findUnique(arr); // output 8

    cout<<ans;
    return 0;
}