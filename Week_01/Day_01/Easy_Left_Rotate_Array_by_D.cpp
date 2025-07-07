#include<iostream>
#include<vector>

using namespace std;

void reverse(vector<int>& arr, int low, int high)
{
    while(low<high)
    {
        swap(arr[low],arr[high]);
        low++;  high--;
    }
}

vector<int> RotateBy_D(vector<int> arr, int D) //D is number of rotaion required
{
    int n = arr.size();

    // We will use reversal algorithm
    reverse(arr,0,D-1);
    reverse(arr,D,n-1);
    reverse(arr,0,n-1);

    return arr;
}



int main()
{
    int D = 3;
    vector<int> v1 = {1,2,3,4,5,67,65};
    vector<int> res = RotateBy_D(v1,D);

    for(int x : res)
    {
        cout<<x<<" ";
    }

    // output:- 4 5 67 65 1 2 3 
    // change D and try to guess the output

    return 0;
}

