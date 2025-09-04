#include <iostream>
#include <vector>
#include<stack>

using namespace std;

vector<int> nextLargerElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;

    for(int i=arr.size()-1; i>=0; i++)
    {
        // step 1:- pop smaller or equal elements
        while(!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }

        // step 2: if stack not empty, top is answe
        if(!s.empty())
        {
            res[i] = s.top();
        }

        // step 3: push current element
        s.push(arr[i]);
    }

    return res;
}

int main()
{
    vector<int> arr = {4, 5, 2, 25};

    vector<int> result = nextLargerElement(arr);

    cout << "Next greater elements are: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
