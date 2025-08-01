#include<iostream>
#include<vector>
   
using namespace std;

double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    // Ensure A is the smaller array
    if (A.size() > B.size()) return findMedianSortedArrays(B, A);

    int n = A.size(), m = B.size();
    int low = 0, high = n;
    int halfLen = (n + m + 1) / 2;

    while (low <= high) {
        int cutA = (low + high) / 2;
        int cutB = halfLen - cutA;

        int Aleft  = (cutA == 0) ? INT_MIN : A[cutA - 1];
        int Aright = (cutA == n) ? INT_MAX : A[cutA];
        int Bleft  = (cutB == 0) ? INT_MIN : B[cutB - 1];
        int Bright = (cutB == m) ? INT_MAX : B[cutB];

        if (Aleft <= Bright && Bleft <= Aright) {
            // Found perfect partition
            if ((n + m) % 2 == 0) {
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else {
                return max(Aleft, Bleft);
            }
        }
        else if (Aleft > Bright) {
            high = cutA - 1; // Move left
        } else {
            low = cutA + 1; // Move right
        }
    }
    return 0.0; // Should never reach here
}

int main() {
    vector<int> A = {1, 3, 8};
    vector<int> B = {7, 9, 10, 11};

    cout << "Median = " << findMedianSortedArrays(A, B) << endl;
    return 0;
}
