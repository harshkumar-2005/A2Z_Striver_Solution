#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// function to check if it is possible to allocate books such that
// no student gets more than 'maxPages'
bool isPossible(const vector<int>& pages, int students, int maxPages) {
    int requiredStudents = 1;
    int currentSum = 0;

    for (int pageCount : pages) {
        if (pageCount > maxPages) {
            return false; // a single book exceeds maxPages
        }

        if (currentSum + pageCount > maxPages) {
            requiredStudents++;
            currentSum = pageCount;

            if (requiredStudents > students) {
                return false;
            }
        } else {
            currentSum += pageCount;
        }
    }

    return true;
}

// Main function to find the minimum possible maximum pages
int allocateBooks(const vector<int>& pages, int students) {
    int n = pages.size();
    if (students > n) return -1; // not enough books

    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(pages, students, mid)) {
            result = mid; // try for a smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> books = {12, 34, 67, 90}; // example pages
    int students = 2;

    int minMaxPages = allocateBooks(books, students);
    cout << "Minimum possible maximum pages: " << minMaxPages << endl;

    return 0;
}
