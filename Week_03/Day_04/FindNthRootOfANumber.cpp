#include<iostream>
#include<vector>

using namespace std;

int NthRoot(int N, int M) 
{
    int low = 1;
    int high = M;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int power = 1;

        for(int i=0; i<N; i++)
        {
            power *= mid;
            if(power > M)   break;
        }

        if(power == M)
        {
            return mid;
        }
        else if(power < M)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int N = 3, M = 27;
    int ans = NthRoot(N,M);
    cout<<ans;

    return 0;
}