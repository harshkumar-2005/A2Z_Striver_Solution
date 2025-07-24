#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to check if we can make 'm' bouquets by 'day'
bool canMakeBouquets(const vector<int>& bloomDay, int day, int m, int k) {
    int bouquets = 0;
    int consecutive = 0;

    for (int bloom : bloomDay) {
        if (bloom <= day) {
            consecutive++;
            if (consecutive == k) {
                bouquets++;
                consecutive = 0; // reset after making a bouquet
            }
        } else {
            consecutive = 0; // reset if rose hasn't bloomed
        }
    }

    return bouquets >= m;
}

int minDaysToMakeBouquets(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();

    // Base case: not enough roses
    if (n < m * k) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canMakeBouquets(bloomDay, mid, m, k)) {
            result = mid;
            high = mid - 1; // try to find a smaller day
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> bloomDay = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;

    int minDay = minDaysToMakeBouquets(bloomDay, m, k);
    cout << "Minimum day to make " << m << " bouquets: " << minDay << endl;

    return 0;
}
