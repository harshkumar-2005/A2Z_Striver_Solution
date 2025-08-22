#include<iostream>

using namespace std;

int fib(int n) 
{
    if(n == 0 || n == 1) return n;

    return fib(n-1) + fib(n-2);
    
}

int main()
{
    int n = 10;
    int res = fib(n);
    cout<< res;

    return 0;
}