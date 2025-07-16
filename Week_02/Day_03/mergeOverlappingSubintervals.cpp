#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1,5},{3,6},{8,10},{15,18}};

    vector<vector<int>> ans = mergeOverlappingIntervals(arr);

    int row = ans.size();
    int col = ans[0].size();

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// output:-
// 1 6 
// 8 10 
// 15 18