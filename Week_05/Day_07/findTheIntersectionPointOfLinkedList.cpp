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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    if(!headA || !headB)
    {
        return nullptr;
    }

    int c1 = 0, c2 = 0;

    ListNode* l1 = headA;
    ListNode* l2 = headB;

    while(l1 != nullptr)
    {
        c1++;
        l1 = l1->next;
    }


    while(l2 != nullptr)
    {
        c2++;
        l2 = l2->next;
    }

    int diff = abs(c1 - c2);

    l1 = headA;
    l2 = headB;

    if(c1 > c2) // l1 is bigger than l2
    {
        for(int i=0; i<diff; i++)
        {
            l1 = l1->next;
        }
    }
    else
    {
        for(int i=0; i<diff; i++)
        {
            l2 = l2->next;
        }
    }

    while(l1 != nullptr && l2 != nullptr)
    {
        if(l1 == l2)
        {
            return l1;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    return nullptr;
}

int main() {
    // Shared part of the lists (intersection starts here)
    ListNode* intersect = new ListNode(7);
    intersect->next = new ListNode(8);

    // List A: 1 -> 2 -> 3 -> 7 -> 8
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = intersect;

    // List B: 4 -> 5 -> 7 -> 8
    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = intersect;

    // Find intersection
    ListNode* result = getIntersectionNode(headA, headB);

    if (result) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
