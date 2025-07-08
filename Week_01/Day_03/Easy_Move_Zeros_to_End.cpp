#include<iostream>
#include<vector>

using namespace std;

vector<int> MoveZeroToEnd(vector<int>& arr)
{

    int j = 0;

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] != 0)
        {
            if(i != j)
            {
                swap(arr[i], arr[j]);
            }
            j++;
        }
        
    }

    return arr;
}

int main()
{

    vector<int> arr = {12,0,0,0,13,14,0,23,0,21,24,0,10};

    vector<int> res = MoveZeroToEnd(arr);


    for(int x : res)
    {
        cout<<x<<" ";
    }

    return 0;
}