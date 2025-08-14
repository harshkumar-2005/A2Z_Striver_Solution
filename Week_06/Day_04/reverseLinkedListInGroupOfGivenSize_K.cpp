#include <iostream>
#include <utility> // for std::pair

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse exactly k nodes starting from 'head'
// Returns {newHead, newTail}
std::pair<ListNode*, ListNode*> reverseKNodes(ListNode* head, int k) 
{
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (k--) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return {prev, head}; // prev = new head, head = new tail
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    if (!head || k <= 1) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prevTail = &dummy;
    ListNode* curr = head;

    while (true) {
        // Step 1: Check if there are at least k nodes left
        ListNode* fast = curr;
        for (int i = 1; i < k && fast; i++) {
            fast = fast->next;
        }
        if (!fast) break; // fewer than k nodes remain

        // Step 2: Store start of next group
        ListNode* nextGroup = fast->next;

        // Step 3: Reverse exactly k nodes
        auto [newHead, newTail] = reverseKNodes(curr, k);

        // Step 4: Connect previous group to reversed group
        prevTail->next = newHead;
        newTail->next = nextGroup;

        // Step 5: Move pointers to the next group
        prevTail = newTail;
        curr = nextGroup;
    }

    return dummy.next;
}

// Utility: Print linked list
void printList(ListNode* head) 
{
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << "\n";
}

// Utility: Create list from array
ListNode* createList(const std::initializer_list<int>& vals) 
{
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

int main() 
{
    ListNode* head = createList({1, 2, 3, 4, 5, 6, 7, 8});
    std::cout << "Original list:\n";
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    std::cout << "Reversed in groups of " << k << ":\n";
    printList(head);

    return 0;
}
