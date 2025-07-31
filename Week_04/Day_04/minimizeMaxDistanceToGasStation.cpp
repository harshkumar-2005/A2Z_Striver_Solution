#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to check if we can achieve maxDist with at most K stations added
bool isPossible(const vector<int>& stations, int K, double maxDist) {
    int needed = 0;
    for (size_t i = 1; i < stations.size(); ++i) {
        double dist = stations[i] - stations[i - 1];
        needed += int(dist / maxDist); // number of stations needed in this gap
    }
    return needed <= K;
}

// Main function to minimize the maximum distance
double minimizeMaxDistance(vector<int>& stations, int K) {
    double left = 0.0, right = stations.back() - stations.front();
    double eps = 1e-6; // precision

    while ((right - left) > eps) {
        double mid = (left + right) / 2.0;
        if (isPossible(stations, K, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    return left;
}

int main() {
    vector<int> stations = {1, 2, 8, 12}; // Example station positions
    int K = 3; // Number of additional gas stations we can add

    double result = minimizeMaxDistance(stations, K);

    cout << fixed << setprecision(6);
    cout << "Minimum possible maximum distance: " << result << endl;

    return 0;
}
