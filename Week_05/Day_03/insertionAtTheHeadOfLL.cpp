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

// Main Function 
 ListNode* insertAtHead(ListNode* &head, int X) 
{
    ListNode* temp = new ListNode(X);

    temp->next = head;

    head = temp;

    return head;
}

int main() {
    ListNode* head = nullptr;  // Start with an empty list

    // Insert some nodes at the head
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);

    // Print the resulting list
    cout << "Linked list after insertions: ";
    ListNode* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }

    // Optional: Clean up memory
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* ptr = current;
        current = current->next;
        delete ptr;
    }

    return 0;
}