#include<iostream>

using namespace std;

// Recursive method

// This have time and space complexity of bigO(n)
double myPow(double x, int n) { // We have to find x^n.
    if(n == 0)
    {
        return 1;
    }

    return x*myPow(x, n-1); 
    
}

// myPow(2, 4)
//    |
//    --> myPow(2, 3)
//           |
//           --> myPow(2, 2)
//                  |
//                  --> myPow(2, 1)
//                         |
//                         --> myPow(2, 0) = 1   <-- base case

// myPow(2, 0) = 1
// ↑
// myPow(2, 1) = 2 * 1 = 2
// ↑
// myPow(2, 2) = 2 * 2 = 4
// ↑
// myPow(2, 3) = 2 * 4 = 8
// ↑
// myPow(2, 4) = 2 * 8 = 16



// other way this is Log(n) time and space.

double OptimisedMyPow(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / myPow(x, -n);
    
    double half = myPow(x, n / 2);
    if (n % 2 == 0) return half * half;
    else return half * half * x;
}

// myPow(2, 13)
//    |
//    --> myPow(2, 6)   // 13 / 2 = 6, odd so multiply extra x later
//           |
//           --> myPow(2, 3)   // 6 / 2 = 3
//                  |
//                  --> myPow(2, 1)   // 3 / 2 = 1
//                         |
//                         --> myPow(2, 0) = 1  <-- base case

// Unwinding the recursion
// From bottom to top:
// myPow(2, 0) = 1
// myPow(2, 1) → odd → (1 * 1 * 2) = 2
// myPow(2, 3) → odd → (2 * 2 * 2) = 8
// myPow(2, 6) → even → (8 * 8) = 64
// myPow(2, 13) → odd → (64 * 64 * 2) = 16384

int main() {
    double base;
    int exponent;

    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;

    double result = myPow(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl;

    return 0;
}
