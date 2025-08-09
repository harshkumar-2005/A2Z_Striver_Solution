#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
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
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr != nullptr)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Input: l1 = head -> 5 -> 4, l2 = head -> 4
// Output: head -> 9 -> 4
// Explanation: l1 = 45, l2 = 4.
// l1 + l2 = 45 + 4 = 49.

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    // Reverse both lists
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    ListNode* head = nullptr;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }

        carry = sum / 10;
        ListNode* newNode = new ListNode(sum % 10);
        newNode->next = head;
        head = newNode;
    }
    return head; // head is already in correct order
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create first list: 5 -> 4  (represents number 54)
    ListNode* l1 = new ListNode(5);
    l1->next = new ListNode(4);

    // Create second list: 4  (represents number 4)
    ListNode* l2 = new ListNode(4);
    l2->next = new ListNode(2);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}