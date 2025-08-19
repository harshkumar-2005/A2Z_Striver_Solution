#include<iostream>
#include<vector>
#include<string>

using namespace std;

void helper(int n, string curr, vector<string> &res)
{
    if(curr.length() == n)
    {
        res.push_back(curr);        return;
    }

    helper(n, curr+"0", res); // always safe to add 0.

    if(curr.empty() || curr.back() != '1') // checking if the last value is 1 or not if not then it is safe to add 1.
    {
        helper(n, curr+"1", res);
    }
}

vector<string> generateBinaryStrings(int n) {
    vector<string> res;
    helper(n,"", res);
    return res;
}

int main() {
    int n;
    cout << "Enter length n: ";
    cin >> n;

    vector<string> result = generateBinaryStrings(n);

    cout << "Binary strings of length " << n << " without consecutive 1s:\n";
    for (string &s : result) {
        cout << s << endl;
    }

    return 0;
}