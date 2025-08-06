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

// Function to insert a node at the head
ListNode* insertAtHead(ListNode* &head, int X) {
    ListNode* temp = new ListNode(X);
    temp->next = head;
    head = temp;
    return head;
}

// Function to get the length of the linked list
int getLength(ListNode* head){
    int cnt=0;
    ListNode *temp = head;
    while(temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

int main() {
    ListNode* head = nullptr;

    // Insert nodes at the head
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30); // List is now: 30 -> 20 -> 10

    // Print the list
    cout << "Linked list: ";
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // Get and print the length
    int length = getLength(head);
    cout << "Length of linked list: " << length << endl;

    // Clean up memory
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}