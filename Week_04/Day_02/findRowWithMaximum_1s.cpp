#include<iostream>
#include<vector>

using namespace std;

int rowWithMax1s(vector < vector < int >> & mat) 
{
    int row = mat.size();
    int col = mat[0].size();
    int max1s = 0;
    int maxRow = -1;

    for (int i = 0; i < row; i++) {
        int count = 0;
        // Since each row is sorted, we can use binary search for 1st 1
        int l = 0, r = col - 1, firstOne = col;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (mat[i][m] == 1) {
                firstOne = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        count = col - firstOne;
        if (count > max1s) {
            max1s = count;
            maxRow = i;
        }
    }
    return maxRow;
}

int main()
{
    vector<vector<int>> mat = { {1, 1, 1}, {0, 0, 1}, {0, 0, 0} };

    int ans = rowWithMax1s(mat);

    cout<<ans;

    return 0;
}

