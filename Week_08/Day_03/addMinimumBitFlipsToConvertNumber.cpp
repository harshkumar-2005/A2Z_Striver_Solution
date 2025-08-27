#include <iostream>
using namespace std;

// algorithm:-
// step 01:- XOR of A and B like A^B.
// step 02:- count the number set bit of that number.
// step 03:- return that count.

// count set bits
long long setBit(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1); // drop the lowest set bit
        count++;
    }
    return count;
}

// return minimum bit flips to convert start → goal
int minBitsFlip(int start, int goal)
{
    return setBit(start ^ goal);
}

int main()
{
    int start = 10; // 1010 in binary
    int goal = 20;  // 10100 in binary

    cout << "Start = " << start << ", Goal = " << goal << endl;
    cout << "Minimum bit flips required = " << minBitsFlip(start, goal) << endl;

    return 0;
}
