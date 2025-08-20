#include<iostream>

using namespace std;

int NnumbersSum(int N)
{
    if(N == 0) return 0;

    int sum = N;
    sum += NnumbersSum(N-1);
    
    return sum;
}

int main()
{
    int n = 100;
    int res = NnumbersSum(n);

    cout<<res;

    return 0;
}