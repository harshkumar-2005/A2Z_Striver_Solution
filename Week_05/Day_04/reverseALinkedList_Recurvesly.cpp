#include<iostream>
#include<vector>

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

ListNode* reverseList(ListNode* head) 
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Recursively reverse from second node
    ListNode* newHead = reverseList(head->next);

    // Now head->next points to last node of reversed list
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

// Print function
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Reverse using recursive function
    head = reverseList(head);

    cout << "Reversed List (Recursive): ";
    printList(head);

    return 0;
}