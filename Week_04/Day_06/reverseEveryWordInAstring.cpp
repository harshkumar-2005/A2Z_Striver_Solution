#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> splitInToWords(string s)
{
    string word = "";
    vector<string> res;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] != ' ')
        {
            word += s[i];
        }
        else
        {
            if(!word.empty())
            {
                res.push_back(word);
                word = ""; //reset for next word;
            }
        }
    }
    if (!word.empty()) 
    {
        res.push_back(word);
    }


    return res;
}

void reverse(vector<string> &res)
{
    int low = 0;
    int high = res.size()-1;

    while(low < high)
    {
        swap(res[low], res[high]);
        low++;  high--;
    }
}

string joinWords(vector<string> &words)
{
    string res = words[0];
    for(int i=1; i<words.size(); i++)
    {
        res += " " + words[i];
    }

    return res;
}

// main function where we will call all the function which are building blocks for the main function.
string reverseWords(string s) 
{
    // First block.
    vector<string> firstBlock = splitInToWords(s);
    // Second block. 
    reverse(firstBlock);
    // Third block 
    string res = joinWords(firstBlock);

    //final return the res
    return res;

}

int main()
{
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);  // allows spaces in input

    string reversed = reverseWords(input);

    cout << "Reversed sentence: " << reversed << endl;

    return 0;
}