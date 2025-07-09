#include<iostream>
#include<vector>

using namespace std;

int maxCountOfOne(vector<int> &arr)
{
    int currMax = 0;
    int finMax = 0;

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == 1)
        {
            currMax++;
            finMax = max(currMax, finMax);
        }
        else
        {
            currMax = 0;
        }
    }

    return finMax;
}

int main()
{

    vector<int> arr = {1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1};
    int res = maxCountOfOne(arr);
    cout<<res; // 5 was the output.
    return 0;
}