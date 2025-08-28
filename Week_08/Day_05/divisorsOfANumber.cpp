#include<iostream>
#include<vector>

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


int main()
{

    return 0;
}