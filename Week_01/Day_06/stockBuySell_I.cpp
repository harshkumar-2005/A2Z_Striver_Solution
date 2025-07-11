#include<iostream>
#include<vector>

using namespace std;

int stockBuySell(vector<int> arr)
{
    int profit =0;

    for(int i = 1; i<arr.size(); i++)
    {
        if(arr[i] > arr[i-1])
        {
            profit += arr[i] - arr[i-1];
        }
    }

    return profit;
}

int main()
{
    vector<int> arr = {10, 7, 5, 8, 11, 9};

    int res = stockBuySell(arr);

    cout<<res; // Output :- 6

    return 0;
}