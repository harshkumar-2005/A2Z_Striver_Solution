#include<iostream>
using namespace std;

bool checkIthBit(int n, int i) 
{
    return (n & (1 << i)) ? true : false;
}

int main()
{
    int n = 19;
    int i = 4;

    cout << "Number: " << n << endl;
    cout << "Checking bit at position " << i << "..." << endl;

    if(checkIthBit(n, i))
        cout << "The " << i << "th bit is SET." << endl;
    else
        cout << "The " << i << "th bit is NOT set." << endl;

    return 0;
}


// n = 19, i = 4
// 19 = 10011
// 1 << i = 1 << 4 = 10000
//    10011   (19)
// &  10000   
// ---------
//    10000  --> not zero so it is set.

