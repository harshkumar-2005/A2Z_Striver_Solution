#include<iostream>

using namespace std;

void printNumbers(int n) 
{
    if(n == 0)return;

    cout<<n<<endl;
    printNumbers(n-1);
}

int main()
{
    int n = 5;
    printNumbers(n);

    return 0;
}