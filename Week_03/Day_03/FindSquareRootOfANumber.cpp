#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long floorSqrt(long long n)
{
    long long ans = 0;

    long long low = 1, high = n;

    while(low <= high)
    {
        long long  mid = (low+high) / 2;
        long long  val = mid * mid;

        if(val == n)
        {
            return mid;
        }
        else if(val < n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 36;

    int ans = floorSqrt(n);

    cout<<ans;

    return 0;
}