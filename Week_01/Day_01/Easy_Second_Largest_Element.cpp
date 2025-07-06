#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int secondLargest(vector<int>& arr)
{
    int first = INT_MIN;
    int second = INT_MIN;

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        if(arr[i]<first && arr[i] > second)
        {
            second = arr[i];
        }

    }

    // for condition like [10,10,10,10,10,10] we must return -1

    if(arr.size() > 1 && second == INT_MIN)
    {
        second = -1;
    }
    
    return second;

}

int main()
{
    vector<int> arr = {21,43,54,23,15,65,44,39,97};

    int answer = secondLargest(arr);

    cout<<"Second Largest Element is :- "<<answer;

    return 0;
}