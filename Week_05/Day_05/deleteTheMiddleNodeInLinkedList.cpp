#include<iostream>

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

ListNode* deleteMiddle(ListNode* head)
{
    // Edge case: only one node
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    // Step 1: Count nodes
    ListNode* temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }

    // Step 2: Find node just before the middle
    int mid = cnt / 2;
    ListNode* curr = head;
    for (int i = 0; i < mid - 1; i++)
    {
        curr = curr->next;
    }

    // Step 3: Delete middle node
    curr->next = curr->next->next;

    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Creating the list: 1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6
    ListNode* n7 = new ListNode(6);
    ListNode* n6 = new ListNode(2, n7);
    ListNode* n5 = new ListNode(1, n6);
    ListNode* n4 = new ListNode(7, n5);
    ListNode* n3 = new ListNode(4, n4);
    ListNode* n2 = new ListNode(3, n3);
    ListNode* head = new ListNode(1, n2);

    cout << "Original List: ";
    printList(head);

    head = deleteMiddle(head);

    cout << "After Deleting Middle Node: ";
    printList(head);

    return 0;
}