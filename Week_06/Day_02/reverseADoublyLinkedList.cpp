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

ListNode* reverseDLL(ListNode* head) 
{
    if(head == nullptr)
    {
        return nullptr;
    }
    if(head->next == nullptr)
    {
        return head;
    }

    ListNode* curr = head;
    ListNode* newHead = nullptr;
    
    while(curr != nullptr)
    {
        ListNode* prenode = curr->prev;
        curr->prev = curr->next;
        curr->next = prenode;

        newHead = curr;
        curr = curr->prev;
    }

    return newHead;
}

void printList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create a doubly linked list: 1 <-> 2 <-> 3 <-> 4
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    cout << "Original list: ";
    printList(head);

    // Reverse the doubly linked list
    head = reverseDLL(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}