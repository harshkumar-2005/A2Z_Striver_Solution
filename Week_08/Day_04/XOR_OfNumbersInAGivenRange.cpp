#include<iostream>

using namespace std;

// Method one:- time big O(n).
int findRangeXOR(int l,int r)
{
    int res = l;

    for(int i=l+1; i<=r; i++)
    {
        res = res ^ i;
    }
    return res;
}

// method 2:- Time big O(1)
// XOR from 0 to n
// int xorUptoN(int n) {
//     if (n % 4 == 0) return n;
//     if (n % 4 == 1) return 1;
//     if (n % 4 == 2) return n + 1;
//     return 0;
// }

// // XOR from l to r
// int findRangeXOR(int l, int r) {
//     return xorUptoN(r) ^ xorUptoN(l - 1);
// }

int main()
{
    int l, r;
    cout << "Enter range (l r): ";
    cin >> l >> r;

    int ans = findRangeXOR(l, r);
    cout << "XOR from " << l << " to " << r << " = " << ans << endl;

    return 0;
}