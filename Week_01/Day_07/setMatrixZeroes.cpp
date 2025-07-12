#include<iostream>
#include<vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    
    int row = matrix.size();
    int col = matrix[0].size();

    bool firstrow = false;
    bool firstcol = false;

    for(int i=0; i<row; i++)
    {
        if(matrix[i][0] == 0)
        {
            firstrow = true;        // first row is zero
            break;
        }
    }

    for(int i=0; i<col; i++)
    {
        if(matrix[0][i] == 0)
        {
            firstcol = true;        // first col is zero
            break;
        }
    }

    for(int i=1; i<row; i++)
    {
        for(int j=1; j<col; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i=1; i<row; i++)
    {
        for(int j=1; j<col; j++)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if(firstrow)
    {
        for(int i=0; i<row; i++)
        {
            matrix[i][0] = 0;
        }
    }
    
    if(firstcol)
    {
       for(int i=0; i<col; i++)
        {
            matrix[0][i] = 0;
        } 
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};

    cout<<"Before calling this function";cout<<endl;
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[0].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    setZeroes(matrix); //function call 

    cout<<"After calling function.";cout<<endl;

    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[0].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// Output:-

// Before calling this function
// 1 1 1 
// 1 0 1 
// 1 1 1 

// After calling function.
// 1 0 1 
// 0 0 0 
// 1 0 1 