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

// Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
// Output: head -> 1 <-> 3 <-> 4 <-> 5

ListNode * removeDuplicates(ListNode *head) 
{
    
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }
    
    ListNode* previ = head;
    ListNode* curr = head->next;
    
    while(curr != nullptr)
    {
        if(curr->val == previ->val)
        {
            previ->next = curr->next;
            if(curr->next != nullptr){
                curr->next->prev = previ;
            }
            delete curr;
            curr = previ->next;
        }
        else
        {
            previ = curr;
            curr = curr->next;
        }
    }

    return head;
}

void printForward(ListNode *head) {
    ListNode *curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        if (curr->next == nullptr) break;
        curr = curr->next;
    }
    cout << endl;
}

void printBackward(ListNode *tail) {
    ListNode *curr = tail;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->prev;
    }
    cout << endl;
}

ListNode *append(ListNode *head, int val) {
    ListNode *newNode = new ListNode(val);
    if (head == nullptr) {
        return newNode;
    }
    ListNode *tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
    return head;
}

int main() {
    ListNode *head = nullptr;

    // Build sorted list with duplicates: 1 1 3 3 4 5
    int arr[] = {1, 1, 3, 3, 4, 5};
    for (int val : arr) {
        head = append(head, val);
    }
    cout << "Original list (forward): ";
    printForward(head);

    // Find tail to print backward
    ListNode *tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    cout << "Original list (backward): ";
    printBackward(tail);

    head = removeDuplicates(head);

    cout << "After removing duplicates (forward): ";
    printForward(head);

    tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    cout << "After removing duplicates (backward): ";
    printBackward(tail);

    return 0;
}