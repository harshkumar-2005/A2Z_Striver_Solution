#include<iostream>
using namespace std;

struct ListNode{
int val;
ListNode* next = nullptr;

ListNode(int x)
{
    val = x;
}

ListNode(int x, ListNode* next1)
{
    val = x;
    next = next1;
}
};
  
int findLengthOfLoop(ListNode *head) 
{
    ListNode* slow = head;
    ListNode* fast = head;
    
    if(head == nullptr || head->next == nullptr)        return 0; 
    
    // check if cycle exist.
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast == slow)    break;
    }
    
    if (!fast || !fast->next) return 0; // no loop

    int size = 1;   
    ListNode* temp = slow->next;
    while(temp != slow)
    {
        size++;
        temp = temp->next;
    }

    return size;
}

int main() {
    // Create nodes
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    // Link them: 1 -> 2 -> 3 -> 4 -> 5
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Create a loop: 5 -> 3
    n5->next = n3;

    cout << "Length of loop: " << findLengthOfLoop(n1) << endl; // Expected: 3

    // Break the loop for testing no-loop case
    n5->next = nullptr;

    cout << "Length of loop: " << findLengthOfLoop(n1) << endl; // Expected: 0

    return 0;
}
