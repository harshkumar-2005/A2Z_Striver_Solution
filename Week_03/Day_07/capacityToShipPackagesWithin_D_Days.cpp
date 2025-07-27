#include<iostream>
#include<vector>
#include<numeric> // for accumulate.
#include<algorithm>

using namespace std;

int findDays(vector<int> &weights, int cap)
{
    int days = 1, load = 0;
    for(int i=0; i<weights.size(); i++)
    {
        if(weights[i] + load > cap)
        {
            days += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }

    return days;
}

int shipWithinDays(vector<int>& weights, int days) 
{
    // it will start with max element of the array and till 
    // the sum of all the element in the array 

    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low<=high)
    {
        int mid = low + (high - low) / 2;
        int numberOfDays = findDays(weights, mid);
        if(numberOfDays <= days)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;

}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    int ans = shipWithinDays(weights, days);

    cout<<ans;

    return 0;
}