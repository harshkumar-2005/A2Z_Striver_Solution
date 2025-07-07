#include<iostream>
#include<vector>

using namespace std;


vector<int> RemoveDuplicates(vector<int>& arr)
{
    int j=0;
    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    // Return only the first j + 1 unique elements
    return vector<int>(arr.begin(), arr.begin() + j + 1);
}

int main()
{
    vector<int> v1 = {1,2,2,3,4,5,6,6,7,7,9,9,10,11,12,32,43,54};
    vector<int> res;

    res = RemoveDuplicates(v1);

    for(int x : res)
    {
        cout<<x<<" ";
    }

    // output:- 1 2 3 4 5 6 7 9 10 11 12 32 43 54 

    return 0;
}