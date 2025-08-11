#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

// Input: head -> 1 <-> 2 <-> 3, X = 3
// Output: head -> 3 <-> 1 <-> 2 <-> 3

ListNode* insertBeforeHead(ListNode* head, int X) 
{
    ListNode* newHead = new ListNode(X);
    newHead->next = head;
    newHead->prev = nullptr;

    if(head != nullptr)
    {
        head->prev = newHead;   // Link back to the new head.
    }

    return newHead;
}

void printListForward(ListNode* head)
{
    ListNode* temp = head;
    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create initial list: 1 <-> 2 <-> 3
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2, node3, nullptr);
    node3->prev = node2;
    ListNode* node1 = new ListNode(1, node2, nullptr);
    node2->prev = node1;

    ListNode* head = node1;

    cout << "Original list: ";
    printListForward(head);

    // Insert before head: X = 3
    head = insertBeforeHead(head, 3);

    cout << "After inserting before head: ";
    printListForward(head);

    return 0;
}