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

bool searchKey(ListNode* head, int key) 
{
    ListNode* temp = head;
    while(temp != nullptr)
    {
        if(temp->val == key)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}


int main() {
    ListNode* head = nullptr;

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30); // List: 30 -> 20 -> 10

    int key = 20;
    if (searchKey(head, key)) {
        cout << "Key " << key << " found in the list." << endl;
    } else {
        cout << "Key " << key << " not found in the list." << endl;
    }

    // Cleanup
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
