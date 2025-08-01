#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool anagramStrings(string& s, string t) 
{
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return (s == t);
}

int main()
{
    string s = "dog";
    string t = "god";

    if(anagramStrings(s, t))
    {
        cout<<"Valid";
    }
    else
    {
        cout<<"InValid";
    }
    return 0;
}