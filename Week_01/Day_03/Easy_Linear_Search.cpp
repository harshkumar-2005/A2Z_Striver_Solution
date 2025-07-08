#include<iostream>
#include<vector>

using namespace std;

int linearSearch(vector<int>& arr, int x)
{
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == x)     return i;
    }

    // Another way if index is not included
    // for(int i : arr)
    // {
    //     if(i == x)      return true;
    // }

    return -1;
}

int main()
{
    vector<int> arr = {1,23,45,74,23,45,65};
    int x = 99;

    cout<<linearSearch(arr , x);


    return 0;
}