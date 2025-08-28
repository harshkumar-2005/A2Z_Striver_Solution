#include <iostream>
#include <vector>
#include <algorithm>  // for sort

using namespace std;

vector<int> divisors(int n) {
    vector<int> res;
    for(int i=1; i*i<=n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i != n/i) res.push_back(n/i); // avoid duplicate when i*i == n
        }
    }
    return res;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> result = divisors(n);

    // Sort the divisors before printing
    sort(result.begin(), result.end());

    cout << "Divisors of " << n << " are: ";
    for(int d : result) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
