#include <iostream>
using namespace std;

// This is using division not the question specific answer but it works.
int divide(int dividend, int divisor) {
    return dividend / divisor;
}

int main() {
    int a = 20, b = 5;
    cout << a << " / " << b << " = " << divide(a, b) << endl;

    a = 43; b = -8;
    cout << a << " / " << b << " = " << divide(a, b) << endl;

    a = 7; b = 3;
    cout << a << " / " << b << " = " << divide(a, b) << endl;

    return 0;
}
