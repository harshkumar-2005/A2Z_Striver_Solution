#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int row = mat.size();
    int col = mat[0].size();

    int low = 0, high = row * col - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midElement = mat[mid / col][mid % col];
        if (midElement == target)
            return true;
        else if (midElement < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    int target = 8;

    if(searchMatrix(mat, target))
    {
        cout<<"Target "<<target<<" is present in the matrix";
    }
    else
    {
        cout<<"The Target "<<target<<" is not present in the matrix";
    }

    return 0;
}