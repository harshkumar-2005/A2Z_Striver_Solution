#include<iostream>
#include<vector>
#include<string>

using namespace std;

string largeOddNum(string& s){
        int n = s.length();
        int i;
        for(i=n-1; i>=0; i--)
        {
            if(s[i] % 2 != 0)
            {
                break;
            }
        }

        // count the leading zero
        int cnt = 0; int j;
        for(j=0; j<n; j++)
        {
            if(s[j] != '0')
            {
                break;
            }
        }

        return s.substr(j, i-j+1);
    }

    int main()
    {

        string s1 = "0214638";
        string s2 = "0000";
        string s3 = "2468";
        string s4 = "13579";
        string s5 = "00013500";

        cout << "Input: " << s1 << ", Output: " << largeOddNum(s1) << endl;
        cout << "Input: " << s2 << ", Output: " << largeOddNum(s2) << endl;
        cout << "Input: " << s3 << ", Output: " << largeOddNum(s3) << endl;
        cout << "Input: " << s4 << ", Output: " << largeOddNum(s4) << endl;
        cout << "Input: " << s5 << ", Output: " << largeOddNum(s5) << endl;

        return 0;
    }