#include<iostream>
#include<vector>
#include<string>
#include<algorithm> // for sort function.

using namespace std;

// method one 
string longestCommonPrefix(vector<string>& str)
{
    string first = str[0];
    int finalcnt = first.size();
    int currcnt;

    for(int j = 1; j < str.size(); j++)
    {
        string t = str[j];
        currcnt = 0;

        for(int i = 0; i < t.size() && i < first.size(); i++)
        {
            if(first[i] == t[i])
            {
                currcnt++;
            }
            else
            {
                break;
            }
        }

        finalcnt = min(finalcnt, currcnt);
    }

    return first.substr(0, finalcnt);
}

/*
// method 2
string longestCommonPrefix(vector<string>& str)
{
    // The idea is to sort the string and then compare first and last string jsut get the common element
    // between them and that's you answer.
    sort(str.begin(), str.end());

    string str1 = str[0];
    string str2 = str[str.size()-1];
    int cnt =0;

    if(str1.size() < str2.size())
    {
        for(int i=0; i<str1.size(); i++)
        {
            if(str1[i] == str2[i])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        for(int i=0; i<str2.size(); i++)
        {
            if(str1[i] == str2[i])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
    }

    return str1.substr(0, cnt);
}
*/

int main()
{
    vector<string> input1 = {"flower", "flow", "flight"};
    vector<string> input2 = {"dog", "racecar", "car"};
    vector<string> input3 = {"interview", "internet", "internal", "into"};

    cout << "LCP of input1: " << longestCommonPrefix(input1) << endl;  // Expected: "fl"
    cout << "LCP of input2: " << longestCommonPrefix(input2) << endl;  // Expected: ""
    cout << "LCP of input3: " << longestCommonPrefix(input3) << endl;  // Expected: "int"

    return 0;
}