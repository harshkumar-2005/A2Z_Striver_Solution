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

ListNode *findStartingPoint(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
            {
                // cycle found 
                fast = head;

                while(fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return nullptr; // no cycle found
}

int main() 
{
    // Create list: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create cycle: 5 → 3
    head->next->next->next->next->next = head->next->next; // 5 points to 3

    // Find start of cycle
    ListNode* cycleStart = findStartingPoint(head);

    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle found in the list." << endl;
    }

    return 0;
}