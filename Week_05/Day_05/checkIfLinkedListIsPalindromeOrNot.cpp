#include<iostream>
#include<string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


bool check(string& s)
{
    int low = 0, high = s.size()-1;

    while(low <= high)
    {
        if(s[low] != s[high])
        {
            return false;
        }

        low++;  high--;
    }
    return true;
}
bool isPalindrome(ListNode* head) {
    string s = "";
    ListNode* temp = head;

    while(temp != nullptr)
    {
        s += to_string(temp->val);
        temp = temp->next;
    }

    if(check(s))
    {
        return true;
    }

    return false;
}

int main()
{
    // Creating the list 1 -> 2 -> 2 -> 1
    ListNode* n4 = new ListNode(1);
    ListNode* n3 = new ListNode(2, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);

    if (isPalindrome(n1))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}