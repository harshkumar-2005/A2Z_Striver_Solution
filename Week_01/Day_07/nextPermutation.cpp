#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> nums = {1,2,3};

    cout<<"Before\n";
    
    for(int x : nums)
    {
        cout<<x<<" ";
    }

    next_permutation(nums.begin(), nums.end()); //function call
    cout<<endl;
    cout<<"After\n";


    for(int x : nums)
    {
        cout<<x<<" ";
    }

    return 0;
}