#include <iostream>
#include <cmath>
using namespace std;

// This Solution has ⚠️ Limitation:

// For large n (e.g., n > 70), floating-point precision errors may cause incorrect results.

// For huge Fibonacci numbers (like F(1000) or F(100000)), it’s better to use matrix exponentiation or fast doubling method (both run in O(log n) time with exact integer results).
// Time : O(1)
// Space : O(1)
int fib(int n) {
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;

    double result = (pow(phi, n) - pow(psi, n)) / sqrt(5);

    return round(result); // rounding handles floating point precision issues
}

// Let’s cover the Fast Doubling Method for Fibonacci.

// This method is based on the following identities:

// F(2k) = F(k) * (2F (k + 1) - F(k))

// F(2k+1)=F(k+1) ^ 2 + F(k) ^ 2

// These allow us to compute Fibonacci numbers in O(log n) time using recursion and integer arithmetic (no floating-point issues like Binet’s formula).
// Returns pair {F(n), F(n+1)}

pair<long long, long long> fib_fast(long long n) {
    if (n == 0) return {0, 1};

    auto [a, b] = fib_fast(n >> 1); // divide n by 2
    long long c = a * (2 * b - a);
    long long d = a * a + b * b;

    if (n & 1) // if n is odd
        return {d, c + d};
    else       // if n is even
        return {c, d};
}

long long fib(long long n) {
    return fib_fast(n).first;
}
// Why use Fast Doubling?

// Unlike Binet’s formula → it works exactly for very large n.

// Example: F(100000) (huge number with ~20,899 digits) can be computed efficiently.

int main() {
    int n = 10;
    cout << fib(n);
    return 0;
}
