#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

//    ^
//   8|                    
//   7|                    
//   6|                    
//   5|             ████
//   4|             ████     ████
//   3|     ████    ████     ████
//   2|     ████    ████     ████    ████
//   1| ███ ████    ████     ████    ████
//    +-------------------------------------> 
//      10   20      30       40      50


// Naive solution:- Considering every bar is smallest of all.

// Time : Big O(n^2)

// int getMaxArea(int arr[], int n)
// {
//     int res = 0;
//     for(int i=0; i<n; i++)
//     {
//         int curr = arr[i];
//         for(int j = i-1; j>=0; j--)
//         {
//             if(arr[j] >= arr[i]){curr += arr[i];}
//             else{break;}
//         }
//         for(int k = i+1; k<n; j++)
//         {
//             if(arr[j] >= arr[i]){curr += arr[i];}
//             else{break;}
//         }
//         res = max(res, curr);
//     }

//     return res;
// }



// Better solution:
// time: Big O(n)

// 1) Initialize : res = 0.
// 2) Find Previous Smaller ELement For Every Element. 
// 3) Find Next Smaller Element For Every Element.
// 4) Do the Following For Every Element arr[i].
                            // curr = arr[i]
                            // curr += (i - ps[i] - 1) * arr[i]
                            // curr += (ns[i] - i - 1) * arr[i]
                            // res = max(res, curr);
// 5) return res

// Efficient Solution:-

int getMaxArea(int arr[], int n)
{
    stack<int> s;  // stack to store indices
    int res = 0;
    int tp;   // to store top of stack
    int curr; // to store current area

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        curr = arr[tp] * (s.empty() ? n : (n - s.top() - 1));
        res = max(res, curr);
    }

    return res;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum area in histogram is: " << getMaxArea(arr, n) << endl;

    return 0;
}
