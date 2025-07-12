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

    return 0;
}