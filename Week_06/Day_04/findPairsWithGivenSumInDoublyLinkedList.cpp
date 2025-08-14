#include<iostream>
#include<vector>

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

vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) 
{
    vector<vector<int>> res;

    if(head == nullptr || head->next == nullptr)
    {
        return res;
    }

    ListNode* start = head;
    ListNode* end = head;
    while(end->next != nullptr)
    {
        end = end->next;
    }
    // Now end is at last node of the linked list 

    while(start != end && end->next != start)
    {
        int sum = start->val + end->val;
        if(sum == target)
        {
            res.push_back({start->val, end->val});
            start = start->next;
            end = end->prev;
        }
        else if(sum > target)
        {
            end = end->prev;
        }
        else
        {
            start = start->next;
        }
    }

    return res;
}

void insertEnd(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}



int main() {
    ListNode* head = nullptr;

    // Sorted DLL
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 4);
    insertEnd(head, 5);
    insertEnd(head, 6);
    insertEnd(head, 8);
    insertEnd(head, 9);

    int target = 7;
    vector<vector<int>> pairs = findPairsWithGivenSum(head, target);

    if (pairs.empty()) {
        cout << "No pair found\n";
    } else {
        for (auto &p : pairs) {
            cout << "(" << p[0] << ", " << p[1] << ")\n";
        }
    }

    return 0;
}