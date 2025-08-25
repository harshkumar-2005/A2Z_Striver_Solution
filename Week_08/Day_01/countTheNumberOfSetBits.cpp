#include <iostream>
using namespace std;

// Brian Kernighan’s Algorithm (faster)
int countSetBits(unsigned int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // clears the lowest set bit
        count++;
    }
    return count;
}

int main() {
    unsigned int num = 29; 
    cout << "Set bits in " << num << " = " << countSetBits(num) << endl;
    return 0;
}
