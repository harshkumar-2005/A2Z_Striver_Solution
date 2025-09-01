#include <iostream>
#include<stack>
#include<string>

using namespace std;

bool isValid(string str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        // If opening bracket, push
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            // If stack empty, invalid
            if (s.empty())
                return false;

            char top = s.top();
            s.pop();

            // Check matching pairs
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
            {
                return false;
            }
        }
    }

    // Stack should be empty if valid
    return s.empty();
}

int main()
{
    string test1 = "([])";
    string test2 = "([)]";
    string test3 = "(((";
    string test4 = "()[]{}";

    cout << test1 << " -> " << (isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << test2 << " -> " << (isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << test3 << " -> " << (isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << test4 << " -> " << (isValid(test4) ? "Valid" : "Invalid") << endl;


    string input;
    cout << "\nEnter a string of brackets: ";
    cin >> input;
    cout << input << " -> " << (isValid(input) ? "Valid" : "Invalid") << endl;

    return 0;
}
