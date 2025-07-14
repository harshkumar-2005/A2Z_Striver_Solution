#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> res;
     // Initialize the pointers reqd for traversal.
  int top = 0, left = 0, bottom = row - 1, right = col - 1;

  // Loop until all elements are not traversed.
  while (top <= bottom && left <= right) {
      
    // For moving left to right
    for (int i = left; i <= right; i++)
      res.push_back(matrix[top][i]);

    top++;

    // For moving top to bottom.
    for (int i = top; i <= bottom; i++)
      res.push_back(matrix[i][right]);

    right--;
    
    // For moving right to left.
    if (top <= bottom) {
      for (int i = right; i >= left; i--)
       res.push_back(matrix[bottom][i]);

      bottom--;
    }

    // For moving bottom to top.
    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        res.push_back(matrix[i][left]);

      left++;
    }
  }
  return res;

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