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


// Given the head of a singly Linked List, return the middle node of the Linked List.
// If the Linked List has an even number of nodes, return the second middle one.
// Function To find the middle Element.
ListNode* middleOfLinkedList(ListNode* head) 
{
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
    
}

int main() {
    // Creating the linked list: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Call the middleOfLinkedList function
    ListNode* middle = middleOfLinkedList(head);

    // Output the middle node's value
    if (middle != nullptr) {
        cout << "Middle node value: " << middle->val << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    // Clean up memory (optional for this small demo)
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}