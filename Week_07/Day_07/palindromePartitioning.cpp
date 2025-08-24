#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}

void findPartitionsHelper(int index, string s, vector<string> &path, vector<vector<string>> &result)
{
    if (index == s.length())
    {
        result.push_back(path);
        return;
    }

    // The loop that tries all possible prefixes (our "cuts")
    for (int i = index; i < s.length(); i++)
    {
        // Check if the current prefix (from index to i) is a palindrome
        if (isPalindrome(s, index, i))
        {
            // If it is, add it to our current path
            path.push_back(s.substr(index, i - index + 1));

            // Make the recursive call to solve for the rest of the string
            findPartitionsHelper(i + 1, s, path, result);

            // This is the crucial backtrack step. We remove the prefix we just added
            // so that the loop can continue and try the next, longer prefix.
            path.pop_back();
        }
    }
}

// The main function that the user calls
vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> path;
    findPartitionsHelper(0, s, path, result);
    return result;
}

int main()
{
    string s = "aabbccbbaa";
    vector<vector<string>> allPartitions = partition(s);

    // Print the results
    for (const auto &p : allPartitions)
    {
        cout << "[ ";
        for (const auto &str : p)
        {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}