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

ListNode* oddEvenList(ListNode* head)
{
    ListNode *os = nullptr;     // Odd Start
    ListNode *oe = nullptr;     // Odd End
    ListNode *es = nullptr;     // Even Start
    ListNode *ee = nullptr;     // Even End

    if(!head || !head->next)
    {
        return head;
    }

    ListNode *curr = head;
    while(curr != nullptr)
    {
        ListNode* nextNode = curr->next;    // storing the next node.
        curr->next = nullptr; // breaking old link
        if(curr->val % 2 == 0) //even value
        {
            if(es == nullptr)
            {
                es = ee = curr;
            }
            else{
                ee->next = curr;
                ee = ee->next;
            }
        }
        else    // Odd value
        {
            if(os == nullptr)
            {
                os = oe = curr;
            }
            else{
                oe->next = curr;
                oe = oe->next;
            }
        }
        curr = nextNode; // Move forward
    }

    if(os == nullptr || es == nullptr)      // All Node are Odd or all are Even
    {
        return head; 
    }

    oe->next = es; 

    return os;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5,
                        new ListNode(6))))));

    cout << "Original list: ";
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Rearrange list with odd numbers first
    head = oddEvenList(head);

    cout << "Odd-first list: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}