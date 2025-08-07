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

bool hasCycle(ListNode *head) 
{
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main() {
    // Create a list: 1 → 2 → 3 → 4 → 5 → nullptr
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    // Test without cycle
    cout << "List 1 has cycle? " << (hasCycle(head1) ? "Yes" : "No") << endl;

    // Create a list with cycle: 10 → 20 → 30 → 40 → 50 → (back to 30)
    ListNode* head2 = new ListNode(10);
    head2->next = new ListNode(20);
    head2->next->next = new ListNode(30);
    head2->next->next->next = new ListNode(40);
    head2->next->next->next->next = new ListNode(50);

    // Create the cycle: 50 → 30
    head2->next->next->next->next->next = head2->next->next;

    // Test with cycle
    cout << "List 2 has cycle? " << (hasCycle(head2) ? "Yes" : "No") << endl;

    return 0;
}