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



ListNode * deleteHead(ListNode* head) 
{
    if(head == nullptr)
    {
        return head;
    }
    if(head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    ListNode* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;

    return head;
}

void printList(ListNode* head)
{
    ListNode* curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    // Create a simple doubly linked list: 1 <-> 2 <-> 3
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);

    head->prev = nullptr;
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Original list: ";
    printList(head);

    // Delete head node
    head = deleteHead(head);
    cout << "After deleting head: ";
    printList(head);

    // Delete head again
    head = deleteHead(head);
    cout << "After deleting head again: ";
    printList(head);

    // Delete head again (last node)
    head = deleteHead(head);
    cout << "After deleting last node: ";
    printList(head);

    return 0;
}