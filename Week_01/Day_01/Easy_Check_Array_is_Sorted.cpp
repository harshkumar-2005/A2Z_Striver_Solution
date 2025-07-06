#include<iostream>
#include<vector>

using namespace std;

bool isSorted(vector<int>& arr)
{
    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i-1] > arr[i])   return false;
    }

    return true;
}

int main()
{

    vector<int> arr = {21,43,54,23,15,65,44,39,97};

    if(isSorted(arr))
    {
        cout<<"COOL! Your array is sorted";
    }
    else
    {
        cout<<"NOPE! Your array is not sorted";
    }

    return 0;
}