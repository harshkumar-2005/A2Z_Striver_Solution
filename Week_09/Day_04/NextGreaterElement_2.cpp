#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums)
{
    int n = nums.size();
    vector<int> res(n, -1);  // default result
    stack<int> st;

    // Traverse the array twice (simulate circular array)
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int idx = i % n;  // wrap around

        // Step 1: Pop smaller or equal elements
        while (!st.empty() && st.top() <= nums[idx])
        {
            st.pop();
        }

        // Step 2: Only fill result during first pass
        if (i < n)
        {
            if (!st.empty())
                res[idx] = st.top();
        }

        // Step 3: Push current element
        st.push(nums[idx]);
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> result = nextGreaterElements(arr);

    cout << "Next greater elements (circular): ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
