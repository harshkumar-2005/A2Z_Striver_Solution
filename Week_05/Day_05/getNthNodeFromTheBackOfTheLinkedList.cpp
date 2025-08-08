#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x)
    {
        val = x;
    }
    ListNode(int x, ListNode* nextNode)
    {
        val = x;
        next = nextNode;
    }
};

ListNode* getNthFromEnd(ListNode* head, int n)
{
    ListNode* slow = head;
    ListNode* fast = slow;

    for(int i=0; i<n; i++)
    {
        if(fast == nullptr)
        {
            return nullptr;
        }
        fast = fast->next;
    }

    while(fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    // Creating linked list: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    ListNode* result = getNthFromEnd(head, n);

    if (result != nullptr)
        cout << "The " << n << "th node from the end is: " << result->val << endl;
    else
        cout << "The list is shorter than " << n << " nodes." << endl;

    return 0;
}
