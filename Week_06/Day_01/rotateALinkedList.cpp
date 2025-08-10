#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next = nullptr;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode* next1)
    {
        val = x;
        next = next1;
    }
};

int LengthOfLL(ListNode* head)
{
    ListNode* curr = head;
    int cnt = 0;

    while(curr != nullptr)
    {
        cnt++;
        curr = curr->next;
    }

    return cnt;
}

ListNode* rotateRight(ListNode* head, int k) 
{
    if (!head || !head->next) return head;
    
    int len = LengthOfLL(head);
    k = k % len;
    if(k == 0)      return head;

    ListNode* newTail = head;
    int newtailpos = len-k;

    for(int i=1; i<newtailpos; i++)
    {
        newTail = newTail->next;
    }


    ListNode* newHead = newTail->next;
    ListNode* temp = newHead;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = head;
    newTail->next = nullptr;

    return newHead;
    
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
    // Manually create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    int k = 2; // rotate by 2
    head = rotateRight(head, k);

    cout << "Rotated list: ";
    printList(head);

    return 0;
}