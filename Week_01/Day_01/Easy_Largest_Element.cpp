#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int LargestElement(vector<int>& arr)
{
    int res = INT_MIN;

    for(int x : arr)
    {
        if(x > res)
        {
            res = x;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {21,43,54,23,15,65,44,39,97};

    int answer = LargestElement(arr);

    cout<<"Largest Element is :- "<<answer;

    return 0;
}