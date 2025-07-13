#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> res;
    

    return res;
    
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4 ,5 ,6}, {7, 8, 9}};

    vector<int> ans = spiralOrder(matrix);

    for(int x : ans)
    {
        cout<<x<<" ";
    }

    return 0;
}

// Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]