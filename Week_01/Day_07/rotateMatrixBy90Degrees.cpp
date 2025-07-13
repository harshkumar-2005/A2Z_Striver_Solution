#include<iostream>
#include<vector>

using namespace std;

void rotateMatrix(vector<vector<int>> &nums)
{
    // Transpose  
    int row = nums.size();
    int col = nums[0].size();

    for(int i=0; i<row; i++)
    {
        for(int j=i+1; j<col; j++)
        {
            swap(nums[i][j], nums[j][i]);
        }
    }

    // reverse the coloum 
    for(int i=0; i<row; i++)
    {
        int low = 0, high = col-1; 
        while(low < high)
        {
            swap(nums[i][low], nums[i][high]);
            low++;    high--;
        }
    }

    // Alternate for reverse the coloum
    // for (int i = 0; i < n; i++) {
    // reverse(matrix[i].begin(), matrix[i].end());
    // }

}

int main()
{
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = nums.size();
    int col = nums[0].size();

    cout<<"Before Rotation\n";

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<nums[i][j];
        }
        cout<<endl;
    }

    //Calling the function 
    rotateMatrix(nums);

    cout<<"After Rotation.\n";

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<nums[i][j];
        }
        cout<<endl;
    }

    return 0;
}


// Output:-
// Before Rotation
// 123
// 456
// 789
// After Rotation.
// 741
// 852
// 963