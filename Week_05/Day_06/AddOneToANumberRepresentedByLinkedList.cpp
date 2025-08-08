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

ListNode *addOne(ListNode *head) {
    long long res=0;

    for(ListNode* ptr = head; ptr!=nullptr; ptr=ptr->next)
    {
        res = res * 10 + ptr->val;
    }
    res = res + 1;  // res++ or res += 1

    ListNode* newHead = nullptr;
    while(res>0)
    {
        int digit = res % 10;
        ListNode* newNode = new ListNode(digit);
        newNode->next = newHead;
        newHead = newNode;
        res = res / 10;
    }

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
    // Create original list: 1 -> 2 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Add one to the number represented by the list
    ListNode* result = addOne(head);

    cout << "List After Adding One: ";
    printList(result);

    return 0;
}
