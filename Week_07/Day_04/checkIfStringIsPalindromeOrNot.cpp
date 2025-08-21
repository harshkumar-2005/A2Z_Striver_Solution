#include<iostream>
#include<string>

using namespace std;


// example of palindrome
// s = "abccba", s = "abcdcba".
bool helper(string& s, int start, int end)
{
    if(start >= end)
    {
        return true; // we have cross the mid so all were same so far.
    }

    if(s[start] != s[end])
    {
        return false;
    }

    return helper(s, start+1, end-1);
}

bool palindromeCheck(string& s)
{
    return helper(s, 0, s.length()-1);
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    if (helper(str, 0, str.size() - 1))
        cout << "Palindrome" << endl;
    else
        cout << "Not a palindrome" << endl;

    return 0;
}