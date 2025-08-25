#include <iostream>

using namespace std;

bool isPowerOfTwo(int n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfTwo(n))
        cout << n << " is a power of two.\n";
    else
        cout << n << " is NOT a power of two.\n";

    return 0;
}
