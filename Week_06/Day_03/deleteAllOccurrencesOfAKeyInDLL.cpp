#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

ListNode* deleteAllOccurrences(ListNode* head, int target) {
    ListNode* curr = head;

    while (curr != nullptr) {
        if (curr->val == target) {
            ListNode* toDelete = curr;

            if (curr->prev != nullptr) {
                curr->prev->next = curr->next;
            } else {
                head = curr->next; // Deleted head
            }

            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }

            curr = curr->next; // Move forward before deleting
            delete toDelete;
        } else {
            curr = curr->next;
        }
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode* append(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        return newNode;
    }
    ListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
    return head;
}

int main() {
    ListNode* head = nullptr;

    // Create list: 1 2 3 2 4 2 5
    int arr[] = {1, 2, 3, 2, 4, 2, 5};
    for (int val : arr) {
        head = append(head, val);
    }

    cout << "Original list: ";
    printList(head);

    int target = 2;
    head = deleteAllOccurrences(head, target);

    cout << "List after deleting " << target << ": ";
    printList(head);

    return 0;
}