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

ListNode *sortList(ListNode *head) 
{
    ListNode* zeroHead = nullptr; 
    ListNode* zeroTail = nullptr;
    ListNode* oneHead = nullptr;  
    ListNode* oneTail = nullptr;
    ListNode* twoHead = nullptr;  
    ListNode* twoTail = nullptr;

    ListNode* curr = head;

    // Step 1: Distribute nodes into three separate lists
    while (curr != nullptr)
    {
        if (curr->val == 0)
        {
            if (zeroHead == nullptr) zeroHead = zeroTail = curr;
            else { zeroTail->next = curr; zeroTail = curr; }
        }
        else if (curr->val == 1)
        {
            if (oneHead == nullptr) oneHead = oneTail = curr;
            else { oneTail->next = curr; oneTail = curr; }
        }
        else
        {
            if (twoHead == nullptr) twoHead = twoTail = curr;
            else { twoTail->next = curr; twoTail = curr; }
        }
        curr = curr->next;
    }

    // Step 2: Connect the three lists
    if (zeroTail != nullptr) zeroTail->next = (oneHead != nullptr) ? oneHead : twoHead;
    if (oneTail != nullptr) oneTail->next = twoHead;
    if (twoTail != nullptr) twoTail->next = nullptr;

    // Step 3: Determine new head
    if (zeroHead != nullptr) return zeroHead;
    else if (oneHead != nullptr) return oneHead;
    else return twoHead;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(0, new ListNode(2, new ListNode(1, new ListNode(0)))));
    
    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);
}
