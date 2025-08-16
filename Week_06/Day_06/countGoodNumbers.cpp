#include<iostream>

using namespace std;

const long long MOD = 1'000'000'007;

long long modPow(long long base, long long exp) {
    long long result = 1 % MOD;
    base %= MOD;  // keep base within modulo

    while (exp > 0) {
        if (exp & 1) { // if exponent is odd
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD; // square the base
        exp >>= 1;                  // divide exponent by 2
    }
    return result;
}


int countGoodNumbers(long long n) 
{
    long long evenPos = (n + 1) / 2; // ceil(n/2)
    long long oddPos  = n / 2;       // floor(n/2)
    long long part1 = modPow(5, evenPos);
    long long part2 = modPow(4, oddPos);
    return (part1 * part2) % MOD;
}

int main() {
    long long n; 
    if (cin >> n) cout << countGoodNumbers(n) << "\n";
    return 0;
}