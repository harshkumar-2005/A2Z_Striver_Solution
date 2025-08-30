#include <iostream>
using namespace std;

class LinkedListQueue {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };
    
    Node* head;  // front of queue
    Node* tail;  // rear of queue

public:
    LinkedListQueue() {
        head = nullptr;
        tail = nullptr;
    }
    
    // Adds element x to the end of the queue
    void push(int x) {
        Node* newNode = new Node(x);
        if (tail) {
            tail->next = newNode;
        }
        tail = newNode;
        if (!head) {  // if queue was empty
            head = newNode;
        }
    }
    
    // Removes and returns the front element
    int pop() {
        if (!head) {
            throw runtime_error("Queue is empty");
        }
        int frontVal = head->val;
        Node* temp = head;
        head = head->next;
        if (!head) {  // if queue becomes empty
            tail = nullptr;
        }
        delete temp;
        return frontVal;
    }
    
    // Returns the front element without removing it
    int peek() {
        if (!head) {
            throw runtime_error("Queue is empty");
        }
        return head->val;
    }
    
    // Returns true if queue is empty
    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    LinkedListQueue queue;
    queue.push(3);
    queue.push(7);
    cout << queue.peek() << endl;   // 3
    cout << queue.pop() << endl;    // 3
    cout << boolalpha << queue.isEmpty() << endl; // false
    return 0;
}
