#include <iostream>
using namespace std;

class Solution {
public:
    bool isOdd(int n) {
        return (n & 1);   // true if odd, false if even
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if(s.isOdd(n))
        cout << n << " is ODD" << endl;
    else
        cout << n << " is EVEN" << endl;

    return 0;
}
