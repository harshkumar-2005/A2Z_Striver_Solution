#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

string frequencySort(string& s) {
    unordered_map<char, int> freq;

    // Step 1: Count character frequencies
    for (char ch : s) {
        freq[ch]++;
    }

    // Step 2: Move frequency data into a vector for sorting
    vector<pair<char, int>> freqVec(freq.begin(), freq.end());

    // Step 3: Sort characters by frequency in descending order
    sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Step 4: Build the output string based on sorted frequency
    string result;
    for (const auto& [ch, count] : freqVec) {
        result.append(count, ch);  // Repeat character `count` times
    }

    return result;
}

int main() {
    string s = "tree";
    string sortedByFreq = frequencySort(s);
    cout << sortedByFreq << '\n';  // Output: "eetr" or "eert"
    return 0;
}
