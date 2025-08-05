#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5},   {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int total = 0;
    
    for (int i = 0; i < s.length(); i++) {
        int value = roman[s[i]];
        int nextValue = (i + 1 < s.length()) ? roman[s[i + 1]] : 0;
        
        if (value < nextValue) {
            total -= value;
        } else {
            total += value;
        }
    }

    return total;
}

int main() {
    string roman = "MCMXCIV";  // 1994
    cout << "Integer: " << romanToInt(roman) << endl;
    return 0;
}
