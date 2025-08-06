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

ListNode* insertAtHead(ListNode* &head, int X) 
{
    ListNode* temp = new ListNode(X);
    temp->next = head;
    head = temp;

    return head;
}

ListNode* deleteHead(ListNode* &head){
    if(head == nullptr)
    {
        return nullptr;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main() {
    ListNode* head = nullptr;

    // Insert some nodes
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30); // List: 30 -> 20 -> 10

    // Delete the head
    head = deleteHead(head); // List becomes: 20 -> 10

    // Print list after deletion
    cout << "List after deleting head: ";
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // Cleanup
    while (head != nullptr) {
        head = deleteHead(head);
    }

    return 0;
}
