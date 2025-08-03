#include<iostream>
#include<vector>

using namespace std;

bool rotateString(string& s,string& goal)
{
    if(s.length() != goal.length())
    {
        return false;
    }

    s += s;

    return (s.find(goal) != string::npos);
}

int main()
{
    string s, goal;

    cout << "Enter the original string: ";
    cin >> s;

    cout << "Enter the goal string: ";
    cin >> goal;

    if (rotateString(s, goal)) {
        cout << "Yes, the goal is a rotation of the original string." << endl;
    } else {
        cout << "No, the goal is NOT a rotation of the original string." << endl;
    }

    return 0;
}