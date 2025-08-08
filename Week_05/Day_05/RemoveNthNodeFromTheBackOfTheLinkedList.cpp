#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next = nullptr;
    ListNode(int x)
    {
        val = x;
    }
    ListNode(int x, ListNode* nextNode)
    {
        val = x;
        next = nextNode;
    }
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;

    for(int i=0; i<n; i++)
    {
        if(fast == nullptr)
        {
            return head;
        }

        fast = fast->next;
    }

    // Special case: removing the head
    if (fast == nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    while(fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* temp = slow->next;
    slow->next = temp->next;
    delete temp;

    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Step 1: Create the list 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    int n = 4;  // Change this value to test different deletions
    head = removeNthFromEnd(head, n);

    cout << "After removing " << n << "th node from end: ";
    printList(head);

    return 0;
}

// output:-
// Original list: 1 -> 2 -> 3 -> 4 -> 5
// After removing 4th node from end: 1 -> 3 -> 4 -> 5